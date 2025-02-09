### Qt library input/output
- Include:
```Cpp
#include <QTextStream> // handle stream like: stdin, stdout, stderr, FILE* ... and some others in/out Qobject
#include <QString>     // like class <string> but optimize for qt
```

- [Using](../_0_Test/_0001_test_inout/main.cpp):
    - `QTexStream object(stream);`
    ``` cpp
    QTextStream qout(stdout);
    qout << "Input your name: ";
    qout.flush();    
    ```


- Note:
    - flush after using QTextStream for output stream, maybe it is using fullbuffer mode.
    - click to object then click F1 for help