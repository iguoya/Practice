#include <QString>
#include <QDebug>
//#include <QtCore>

// text stream is text-codec aware
//QTextStream qDebug()(stdout, QIODevice::WriteOnly);

int main(int argc, char *argv[])
{
    // avoid compiler warnings
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    QString s1("Paris");
    QString s2("London");
    // string concatenation
    QString s = s1 + " " + s2 + "!";
    qDebug() << s << endl;

    QString str1 = QString("%1 's age is %2").arg("tiger").arg(32);
    qDebug()<<str1;


    QString s3("Hello");
    QString s4("Qt");
    QList<QString> list;
    // stream into containers
    list <<  s3 << s4;
    // Java and STL like iterators
    QListIterator<QString> iter(list);
    while(iter.hasNext()) {
        qDebug() << iter.next();
        if(iter.hasNext()) {
            qDebug() << "   ";
        }
    }
    qDebug() << "!" << endl;

    QStringList slist;
    slist <<  s3 << s4;
    // join strings
    QString ss = slist.join(" -- ") + "!";
    qDebug() << ss << endl;
}
