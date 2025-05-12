#include "serial.h"
#include <stdio.h>
int main()
{
    //serial init
    Serial* serial = new Serial("COM7", 115200);

    if (!serial->isConnected()) return 0;

    char buf[255];
    while (1) {
        serial->readLine(buf, 255);

        short ax, ay, az, btn1, btn2;

        bool m_state[2];


        //파싱에 성공한 변수 return
        sscanf(buf, "%d,%d,%d,%d,%d", &ax, &ay, &az, &btn1, &btn2);

        // 마우스 클릭
        if ((btn1 == 0) && m_state[0]) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            printf("lclick\n");
        }
        else if ((btn1 == 1) && !m_state[0]) {
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            printf("luclick\n");
        }
        if ((btn2 == 0) && m_state[1]) {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            printf("Rclick\n");
        }
        else if ((btn2 == 1) && !m_state[1]) {
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            printf("Ruclick\n");
        }
        m_state[0] = btn1;
        m_state[1] = btn2;


        //MPU6050 으로 읽어온 가속도 값을 적용 시킬 변수
        int off_x = -(ax / 1000) * 3;
        int off_y = (ay / 1000) * 3;


        POINT p;
        GetCursorPos(&p);
        //MPU6050 으로 읽어온 가속도 값을 적절하게 적용해야 한다.
        SetCursorPos(p.x + off_x, p.y + off_y);

    }
    return 0;
}