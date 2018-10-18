#include<QDebug>
typedef quint8 byte;
typedef quint32 word;
#define word_hhi(x) ((byte)((word)((word)(x)>>24)))//最高八位
#define word_lhi(x) ((byte)((word)((word)(x)>>16)&255))//次高八位
#define word_hlo(x) ((byte)(((word)(x)>>8)&255))//次低八位
#define word_llo(x) ((byte)((word)(x)&255))//最低八位
#define Max(x,y) (((x)>(y))?(x):(y))//最大值
#define Min(x,y) (((x)<(y))?(x):(y))//最小值
int main(int argc, char *argv[])
{
    int k=0x12345678;
    QList<qint8> values;
    values.append(word_hhi(k));
    values.append(word_hlo(k));
    values.append(word_lhi(k));
    values.append(word_llo(k));
    qDebug("原始值:0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",
           k,k,values.at(0),values.at(0),values.at(1),values.at(1),values.at(2),values.at(2),values.at(3),values.at(3));
    qDebug("最高八位与次高八位的最大值:0x%x(%d)\n次低八位与最低八位的最小值:0x%x(%d)",
           Max(values.at(0),values.at(2)),Max(values.at(0),values.at(2)),Min(values.at(1),values.at(3)),Min(values.at(1),values.at(3)));
    qDebug()<<"排序前:"<<values;
    //计算重组后的值
    int new_k;
    new_k=(values.at(1)<<24)+(values.at(0)<<16)+(values.at(3)<<8)+values.at(2);
    qDebug("重组后:0x%x(%d)",new_k,new_k);
    std::sort(values.begin(),values.end(),std::greater<qint8>());//排序
    qDebug()<<"排序后:"<<values;
}

