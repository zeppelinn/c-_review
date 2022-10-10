//
// Created by LiJun on 2022/10/10.
//

#include <iostream>
#include <QApplication>

extern "C" {
#include<libavdevice/avdevice.h>
}

using namespace std;

int main()
{
    cout << "avdevice_license--> " << avdevice_license() << endl;
    cout << "avcodec_configuration-->" << avcodec_configuration() << endl;

    return 0;
}