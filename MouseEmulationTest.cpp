#include <Windows.h>

int main()
{
    while (true)
    {
        //При нажатии клавиши F7 курсор передвинется при помощи raw пакета, такой же метод используется в остальных функциях эмуляци в windows
        if (GetAsyncKeyState(VK_F7) & 0x8000)
        {
            mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 100, 200, 0, 0);
            while (GetAsyncKeyState(VK_F7) & 0x8000)
            {
                Sleep(1);
            }
        }

        //При нажатии F8 курсор сдвинется программно, без отправки пакета
        if (GetAsyncKeyState(VK_F8) & 0x8000)
        {
            SetCursorPos(500, 300);
            while (GetAsyncKeyState(VK_F8) & 0x8000)
            {
                Sleep(1);
            }
        }

        Sleep(1);
    }

    return 0;
}