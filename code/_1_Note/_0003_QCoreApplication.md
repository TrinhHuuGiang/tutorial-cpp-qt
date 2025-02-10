### Content
- [About Class QCoreApplication](#qcoreapplication)
- [some Member functions](#member-function)
<<<<<<< HEAD
    1. **Public Functions**
=======
    1. Public Functions
>>>>>>> 16c88ecc3d0c58cbea9a40725cb0e0086186e958
    - QCoreApplication |~QCoreApplication
    - checkPermission |requestPermission
    - installNativeEventFilter |removeNativeEventFilter
    - notify

<<<<<<< HEAD
    2. **Public Slots**
    - exit
    - quit
    
    3. **Signals**
=======
    2. Public Slots
    - exit
    - quit
    
    3. Signals
>>>>>>> 16c88ecc3d0c58cbea9a40725cb0e0086186e958
    - aboutToQuit
    - applicationNameChanged |applicationVersionChanged
    - organizationDomainChanged |organizationNameChanged

<<<<<<< HEAD
    4. **Static Public Members**
    - addLibraryPath |libraryPaths |removeLibraryPath |setLibraryPaths
    - applicationDirPath |applicationFilePath |applicationName |applicationPid |applicationVersion |
=======
    4. Static Public Members
    - addLibraryPath |libraryPaths |removeLibraryPath |setLibraryPaths
    - applicationDirPath |applicationFilePath |applicationName |applicationPid |applicationVersion |  
>>>>>>> 16c88ecc3d0c58cbea9a40725cb0e0086186e958
    setApplicationName |setApplicationVersion
    - arguments
    - closingDown |startingUp
    - eventDispatcher |setEventDispatcher
    - exec
    - installTranslator |removeTranslator |translate
    - instance
    - isQuitLockEnabled |setQuitLockEnabled
    - isSetuidAllowed |setSetuidAllowed
    - organizationDomain |organizationName |setOrganizationDomain |setOrganizationName
    - postEvent |removePostedEvents |sendPostedEvents
    - processEvents |sendEvent
    - setAttribute |testAttribute
    
<hr>

### QCoreApplication
- **References:**
    - [Documentation](https://doc.qt.io/qt-6.5/qcoreapplication.html)  

- **Inherits**: QObject class

- **Purpose:**
    - This class is used for non-GUI applications (console-based programs) to manage event (signals - slots) throughout run-time.  
    - It handles the application's:
        - Initialization, system-wide and application-wide settings.  
            - `QCoreApplication(int &argc, char **argv)`
        - Finalization (cleanup before the application exits).  
        - **QCoreApplication manages the main event loop:**
            - Receives event signals from the OS, processes, threads, etc., and send it to right slots.  
    - Only **one instance** of `QCoreApplication` should be used per application; creating multiple instances will cause errors.  
    - When using a QObject, ensure that the QCoreApplication object is initialized first in the main() function.  
<hr>

### Member function
## exec()
- Enters the main event loop to manage all event. Required for handling signals, slots, and event-driven programming.  
- exit when call `exit(error code)` or `quit()` function after `exec()` has been started
- On some platforms (e.g., Windows), the application may terminate immediately if the system forces it to close (e.g., user logs off). Solution to clean and save jobs:  
    - Connect cleanup tasks to `aboutToQuit()` instead of relying on code after `exec()` to ensure proper resource cleanup.  
    ```cpp
    #include <QCoreApplication>
    #include <QObject>
    #include <QDebug>

    int main(int argc, char *argv[]) {
        QCoreApplication app(argc, argv);

        // Connect aboutToQuit() to a cleanup function
        QObject::connect(&app, &QCoreApplication::aboutToQuit, []() {
            qDebug() << "Cleaning up before exit...";
            // Perform cleanup tasks here (e.g., closing files, releasing memory)
        });

        qDebug() << "Application is starting...";
        
        // Start the event loop
        return app.exec(); 

        // Any code here will only run if exec() exits, which may not always happen on all platforms.
    }
    ```
<hr>

2. 