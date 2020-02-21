#include <QtCore>
QTextStream cout(stdout, QIODevice::WriteOnly);
int main(int argc, char *argv[])
{

    Q_UNUSED(argc)
    Q_UNUSED(argv)
    QString s1("Paris");
    QString s2("London");
    // string concatenation
    QString s = s1 + " " + s2 + "!";
    cout << s << endl;


    QString s3("Hello");
    QString s4("Qt");
    QList<QString> list;
    // stream into containers
    list << s3 << s4;
    // Java and STL like iterators
    QListIterator<QString> iter(list);
    while(iter.hasNext()) {
        cout << iter.next();
        if(iter.hasNext()) {
            cout << " ";
        }
    }
    cout << "!" << endl;


    QStringList data;
    // file operations
    QFile file("sample.csv");
    if(file.open(QIODevice::ReadOnly)) {

        QTextStream stream(&file);
        // loop forever macro
        forever {
            cout << "ccccc" << endl;
            QString line = stream.readLine();
            // test for null string 'String()'
            if(line.isNull()) {
                break;
            }
            // test for empty string 'QString("")'
            if(line.isEmpty()) {
                continue;
            }
            QStringList row;
            // for each loop to iterate over containers
            foreach(const QString& cell, line.split(",")) {
                row.append(cell.trimmed());
            }
            data.append(row);
        }
    }


    for (QStringList::iterator it = data.begin(); it != data.end(); ++it)
    {
        qDebug() << *it;
    }

    cout << "kkkkk" << endl;

}
