#include <QCoreApplication>
#include <QVector>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<QString> numb,name,cou1,cou2;

    numb<<"1403130209"<<"1403140101"<<"1403140102"<<"1403140103";

    name<<"鲁智深"<<"林冲"<<"宋江"<<"武松";

    cou1<<"80"<<"82"<<"76"<<"88";

    cou2<<"72"<<"76"<<"85"<<"80";

    qDebug()<<"："<<endl<<numb<<endl<<name<<endl<<cou1<<endl<<cou2<<endl;

    QVector<QVector<QString>> transcript;

    transcript<<numb<<name<<cou1<<cou2;

    qDebug()<<"按姓名排序：";

    std::sort(name.begin(),name.end(),std::greater<QString>());

    int j,k;

    for(j=0;j<name.size();j++)
    {

        for(k=0;k<name.size();k++)

        {

            if(name.at(j)==transcript.at(1).at(k))

                break;

        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(k)<<transcript.at(2).at(k)<<transcript.at(3).at(k);
        }

    }

    qDebug()<<"按课程1的成绩排序：";

    std::sort(cou1.begin(),cou1.end(),std::greater<QString>());

    for(j=0;j<cou1.size();j++)
    {

        for(k=0;k<cou1.size();k++)
        {

            if(cou1.at(j)==transcript.at(2).at(k))

                break;

        qDebug()<<transcript.at(0).at(k)<<transcript.at(1).at(k)<<transcript.at(2).at(k)<<transcript.at(3).at(k);
        }

    }

    qDebug()<<"按课程2的成绩排序：";

    std::sort(cou2.begin(),cou2.end(),std::greater<QString>());

    for(j=0;j<cou2.size();j++){

        for(k=0;k<cou2.size();k++)

            if(cou2.at(j)==transcript.at(3).at(k))

                break;

        qDebug()<<transcript.at(0).at(k)<<transcript.at(1).at(k)<<transcript.at(2).at(k)<<transcript.at(3).at(k);

    }

    return a.exec();

}
