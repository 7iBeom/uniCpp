// TV 클래스와 객체

#include <iostream>
using namespace std;

class TV {
    bool on;
    int channel;
    int volume;
public:
    TV() { // 매개 변수가 없는 생성자 (자동 초기화) // Overriding // 다형성
        on = false;
        channel = 0;
        volume = 5;
    }
    TV(int cha, int vol) { // 매개 변수가 있는 생성자
        on = false;
        channel = cha;
        volume = vol;
    }
    void powerOn();
    void powerOff();
    void increaseChannel();
    void decreaseChannel();
    void increaseVolume();
    void decreaseVolume();
    void showTV();
};

void TV::powerOn() {
    on = true;
}

void TV::powerOff() {
    on = false;
}

void TV::increaseChannel() {
    if(on)
        channel = (channel + 1) % 100; // 안전장치
}

void TV::decreaseChannel() {
    if(on)
        channel = (channel - 1) % 100;
}

void TV::increaseVolume() {
    if(on)
        if(volume <= 100)
            volume++;
        else {}
}

void TV::decreaseVolume() {
    if(on)
        if (volume > 0)
            volume--;
        else {}
}

void TV::showTV() {
    if(on == 1)
        cout << "TV전원: ON" << "\tTV 채널: " << channel << "\tTV 볼륨: " << volume << endl;
    else
        cout << "TV전원: OFF" << endl;
}

int main() {
    TV samsung(10, 15);
    samsung.powerOn();
    samsung.increaseChannel();
    samsung.showTV();

    TV lg;
    lg.showTV();

}