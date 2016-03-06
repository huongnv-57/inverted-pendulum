//#include <iostream>
//#include "pid.h"
//#include <QDebug>

//using namespace std;

//int main(){
//    qDebug()<<"testing pid";
//    PID P1;
//    P1.setRefreshInterval(0.02);
//    P1.setDesiredPoint(0.0);
//    P1.setErrorThreshold(0.001);
//    P1.setOutputLowerLimit(-1);
//    P1.setOutputUpperLimit(1);
//    P1.setWeights(0.0001,0.000001,0.0001);

//    float r;
//    r = P1.refresh(0.5235);
//    qDebug()<<r*1000;

//    return 0;
//}





#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QUrl>
#include <QQmlContext>
#include <iostream>
#include <QTime>
#include "pendulum.h"
#include <cmath>
#define PI 3.14
void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Pendulum sample1(30.0,0);

    QString theta = QString::number(sample1.getAng());
    QString posn = QString::number(sample1.getPosn());
    engine.rootContext()->setContextProperty("theta", theta);
    engine.rootContext()->setContextProperty("posn", posn);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    delay(100);
    for(int i =0;i<60;i++){
        // thuc hien tinh toan vi tri moi cho con lac
        sample1.calNext();
        qDebug()<<sample1.control.getLastErr();

        //
        QString theta = QString::number(sample1.getAng());
        QString posn = QString::number(sample1.getPosn());
        engine.rootContext()->setContextProperty("theta", theta);
        engine.rootContext()->setContextProperty("posn", posn);
        delay(100);

    }
//    qDebug()<<sample1.angle;
//    sample1.calNext();
//    qDebug()<<sample1.angle;

    return app.exec();
}
