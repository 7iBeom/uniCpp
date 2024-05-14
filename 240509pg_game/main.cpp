#include<iostream>
#include<typeinfo>
using namespace std;

class Character
{
protected:
	double x, y, hp, mp, range, speed;
public:

	Character(double x, double y, double hp,double mp, double range, double speed)
	{
		this->x = x; this->y = y;
		this->hp = hp;
		this->mp = mp;
		this->range = range; this->speed = speed;
	}
	virtual void attack(Character* c) = 0;
	virtual bool hpFull() = 0;
	virtual bool mpFull() = 0;
	virtual void hpMax() = 0;
	virtual void mpMax() = 0;

	void move(double dstX, double dstY)
	{
		double mx, my;
		mx = my = speed;
		if (dstX < x)
			mx = -mx;
		for (; int(dstX * 10) != int(x * 10); x += mx);
		if (dstY < y)
			my = -my;
		for (; int(dstY * 10) != int(y * 10); y += my);
	}
	void punch(Character* c)
	{
		double dist = distance(this, c);
		if (c->hp > 0 && dist <= 1)
			c->hp -= 1;
		else
			cout << "범위 내 대상이 없습니다." << endl;
	}
	void info(string c, int i)
	{
        c = c.substr(1);
        if (c == "Archer")
        {
            cout << c << "["<<i<<"]" << " pos = (" << x << ", " << y << "), hp = " << hp << ", archer = " << mp << endl;
        }   
        else if (c == "Assassin")
        {
			if (x == 10000 || y == 10000) 
				cout << c << "["<<i<<"]" << " pos = [위치를 알 수 없습니다], hp = " << hp << ", energy = " << mp << endl;
			else
				cout << c << "["<<i<<"]" << " pos = (" << x << ", " << y << "), hp = " << hp << ", energy = " << mp << endl;
        }
        else
        {
            cout << c << "["<<i<<"]" << " pos = (" << x << ", " << y << "), hp = " << hp << ", mp = " << mp << endl;
        }
        
	}
	double distance(Character *c1, Character *c2) {
		double a = c1->x - c2->x;
		double b = c1->y - c2->y;
		double cSQ = a * a + b * b;
		return sqrt(cSQ);
	}
	friend class SwordsMan;
	friend class Priest;
    friend class Wizard;
    friend class Archer;
    friend class Assassin;
};

class SwordsMan : public Character
{
public:
	SwordsMan(double x = 0, double y = 0, double hp = 80, double range = 2, double speed = 0.1)
		: Character(x, y, hp, 0.0, range, speed) {}
	virtual bool hpFull() { return hp >= 80; }
	virtual bool mpFull() { return mp >= 0; }
	virtual void hpMax() { hp = 80; }
	virtual void mpMax() { mp = 0; }

	virtual void attack(Character* c)
	{
		double dist = distance(this, c);
		if (c->hp > 0 && dist <= range)	// range는 정상접근 가능.
			c->hp -= 10; // 현재위치는 c의 입장에서 외부임. friend 없이 사용불가
		else
			cout << "범위 내 대상이 없습니다." << endl;
	}
	void run(double dstX, double dstY)
	{
		if (hp > 20)
		{
            hp -= 5;
			double temp = speed;
			speed = 0.5;
			move(dstX, dstY);
			speed = temp;
		}
	}
};

class Wizard : public Character
{
public:
    Wizard(double x = 0, double y = 0, double hp = 30, double mp = 80, double range = 5, double speed = 0.1)
        : Character(x, y, hp, mp, range, speed) {}

    virtual bool hpFull() { return hp >= 30; }
	virtual bool mpFull() { return mp >= 80; }
	virtual void hpMax() { hp = 30; }
	virtual void mpMax() { mp = 80; }
	virtual void attack(Character* c)
	{
		double dist = distance(this, c);
        if (c->hp > 0 && dist <= range && mp > 5)
        {
            c->hp -= 5;
            mp -= 5;
        }
        else 
            cout << "범위 내 대상이 없습니다." << endl;
	} 
    void teleport(double dstX, double dstY)
    {
        move(dstX, dstY);
    }
    void mpcharge()
    {
        if (hp > 5) {
            hp -= 5;
            mp += 20;
        }
        
        if (mpFull()) mpMax();
			
		if (mp < 0) mp = 0;
    }
    
};

class Archer : public Character
{
public:
    Archer(double x = 0, double y = 0, double hp = 40, double mp = 5, double range = 10, double speed = 0.2)
        : Character(x, y, hp, mp, range, speed) {}

    virtual bool hpFull() { return hp >= 40; }
	virtual bool mpFull() { return mp >= 0; }
	virtual void hpMax() { hp = 60; }
	virtual void mpMax() { mp = 0; }
    bool arrowFull() { return mp >= 5; } 
    void arrowMax() { mp = 5; }


	virtual void attack(Character* c)
	{
		double dist = distance(this, c);
        if (c->hp > 0 && dist <= range && mp >= 1)
        {
            c->hp -= 5;
            mp -= 1;
        }
        else 
            cout << "범위 내 대상이 없습니다." << endl;
	}
    void reload()
    {
        mp += 2;

        if (arrowFull()) arrowMax();
			
		if (mp < 0) mp = 0;
    }
};

class Priest : public Character
{
public:
	Priest(double x = 0, double y = 0, double hp = 60, double mp = 80, double range = 5, double speed = 0.1)
		: Character(x, y, hp, mp, range, speed) {}
	
	virtual bool hpFull() { return hp >= 60; }
	virtual bool mpFull() { return mp >= 80; }
	virtual void hpMax() { hp = 60; }
	virtual void mpMax() { mp = 80; }
	virtual void attack(Character* c)
	{
		punch(c);
	}
	void hpHeal(Character* c)
	{
		double dist = distance(this, c);
		if (!c->hpFull() && dist <= range && mp >= 5)	// range는 정상접근 가능.
		{
			c->hp += 10; // 현재위치는 c의 입장에서 외부임. friend 없이 사용불가
			if (c->hpFull()) c->hpMax();
			mp -= 5;
			if (mp < 0) mp = 0;
			
		}
		else
			cout << "범위 내 대상이 없습니다." << endl;
	}
	void mpHeal(Character* c)
	{
		double dist = distance(this, c);
		if (!c->mpFull() && dist <= range && mp >= 5)	// range는 정상접근 가능.
		{
			mp -= 5;
			c->mp += 10; // 현재위치는 c의 입장에서 외부임. friend 없이 사용불가
			if (c->mpFull()) c->mpMax();
			
			if (mp < 0) mp = 0;

		}
		else
			cout << "범위 내 대상이 없습니다." << endl;
	}
    void mpcharge()
    {
        if (hp > 5) {
            hp -= 5;
            mp += 20;
        }
        
        if (mpFull()) mpMax();
			
		if (mp < 0) mp = 0;
    }
};

// 암살자 클래스
class Assassin : public Character 
{
public:
    Assassin(double x = 0, double y = 0, double hp = 60, double mp = 20, double range = 5, double speed = 0.5)
		: Character(x, y, hp, mp, range, speed) {}
	
	bool ambushCheck = false;
	virtual bool hpFull() { return hp >= 60; }
	virtual bool mpFull() { return mp >= 20; }
	virtual void hpMax() { hp = 60; }
	virtual void mpMax() { mp = 20; }
	double temp;
	double cbx, cby;

	virtual void attack(Character* c)
	{
		double dist;
		if (ambushCheck) {
			move(cbx, cby);
			dist = distance(this, c);
			if (c->hp > 0 && dist <= range)
        	{	
            	c->hp -= 20;
				speed = temp;
				ambushCheck = false;
       		}
			else 
            	cout << "범위 내 대상이 없습니다." << endl;
		}
		else {
			if (c->hp > 0 && dist <= range)
        	{
            	c->hp -= 5;
       		}
			else 
            	cout << "범위 내 대상이 없습니다." << endl;
		}
	}
	// 매복 함수
	void ambush()
    {	
		temp = speed;
		this->speed = 1.0;
		cbx = x; cby = y;
		// 상대 공격 범위 밖으로 이동
        move(10000, 10000);
		mp -= 15;
		ambushCheck = true;
    }
	// 기력 회복 함수
	void energyRecovery() {
		mp += 10;
	}
};

int main()
{
	Character* c[6];
	
    c[4] = new Archer(1, 1);
	c[5] = new Assassin(1, 0);

	((Assassin*)c[5])->ambush();
	c[4]->attack(c[5]);
	
	c[4]->info((typeid(*c[4])).name(), 4);
	c[5]->info((typeid(*c[5])).name(), 5);

	c[5]->attack(c[4]);

	c[4]->info((typeid(*c[4])).name(), 4);
	c[5]->info((typeid(*c[5])).name(), 5);


	return 0;
}