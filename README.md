[![C/C++ CI](https://github.com/flari949/COSC345-Eventures/actions/workflows/workflow.yml/badge.svg)](https://github.com/flari949/COSC345-Eventures/actions/workflows/workflow.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/198761ccc0644b26b6df4f6158db10e4)](https://app.codacy.com/gh/flari949/COSC345-Eventures/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Documentation](https://codedocs.xyz/lukePiper03/COSC345-Eventures.svg)](https://codedocs.xyz/lukePiper03/COSC345-Eventures/)
[![codecov](https://codecov.io/gh/flari949/COSC345-Eventures/graph/badge.svg?token=FQWN4J2M0E)](https://codecov.io/gh/flari949/COSC345-Eventures)

# COSC345 Project
## About the Project
The Eventures application project is a group project for the COSC345 university paper at the University Of Otago. This project aims to design and create a useful application for the betterment of a user or society with the primary programming language as C/C++. The project requires the incorporation of two or more publicly available datasets (of different data domains) that can be combined to create additional meaning.

### What is Eventures
> Eventures aims to combine [EventFinda](eventfinda.co.nz) event data along with [ArcGIS](https://www.arcgis.com/apps/mapviewer/index.html) geographical mapping services data to superimpose event data on a visual interface for a unique and valuable exploration and discovery application.

### Eventures Questionnaire
Link to Questionnaire: https://www.surveymonkey.com/r/QFQFH97

## Installation Guide
**Tested with Software Versions:**
- C++ compiler supporting the C++17 standard
- Qt-unified-windows-x64 (Installation Software): Version 4.6.0-online
- Qt: Version 6.5.2
- Qt Creator: Version 11.0.2
- CMake: Version 3.24.2
- Ninja: Version 1.10.2
- MSVC: Version 2019; System: 64-bit


### Prerequisites
There are two available methods for configuring and executing the project: through the command line or within the QT Creator application. In either approach, it's necessary to have the following software installed and properly configured on your system:

1. **Qt Creator - Open-Source:**
   - [Download Qt Online Installer](https://www.qt.io/download-open-source)
   - Open the installation wizard and advance to the installation folder
   - Select custom installation
   - Select the most recent full-release version of Qt and the following components:
     - Under the selected version, select the **MSVC 2019** version corresponding to the user system and the **Sources** component.
     - Under <ins>Additional Libraries</ins> select **Qt Multimedia**, **Qt Positioning**, **Qt Sensors**, and **Qt Websockets**.
     - Under <ins>Developer and Designer Tools</ins> select **Qt Creator** + **Debugger Support**, **Debugging Tools**, **Debug Symbols**, **Plugin Development**, **Qt Installer Framework**, **CMake**, and **Ninja**. 
   - Progress through installation.
  
2. **ArcGIS Maps SDK for Qt:**
   - [Create an ArcGIS account](https://www.arcgis.com/sharing/rest/oauth2/signup?client_id=arcgisonline&redirect_uri=http://www.arcgis.com&response_type=token).
   - Login to the [ArcGIS Developer site](https://developers.arcgis.com/dashboard/) with the created account and navigate to the dashboard tab.
   - Navigate to the [Downloads tab](https://developers.arcgis.com/downloads/).
   - Select the **ArcGIS Runtime SDK for Qt** download corresponding to the user system.
   - Run the SDK installer once downloaded.
   - On completetion, run the **ArcGIS Runtime SDK for Qt Post Installer** and connect the SDK to the Qt Installation.
   - **For troubleshooting and more info see the [ArcGIS for Qt installations page](https://developers.arcgis.com/qt/install-and-set-up/).**

3. **Clone The Repository:**
   - Open a terminal and navigate to your preferred directory.
   - Clone the repository:
     ```
     git clone https://github.com/flari949/COSC345-Eventures.git
     ```
4. **ArcGIS SDK Qt Connection:**
   - Within the Eventures directory, open include>arcgis_runtime_qml_cpp.pri.
   - Find the SDK_INSTALL_DIR variable and ensure it is set to the location of the ArcGIS SDK Qt installation.
     - By default, the installation should be under:
       ```
       "C:/Program Files/ArcGIS SDKs/Qt200.2.0"
       ```

## Project Setup with QT
### **Compiling**
- Open Qt Creator
- Select: File/Open File or Project/ (Ctrl + O)
- Navigate to and select the Eventures.pro file within the repository
    ```
    Path/to/repository/COSC345-Project/Eventures/Map_display.pro
    ```
- Within the projects section of Qt Creator:
  - Change and ensure the debug build directory is set to `\Eventures`.
  - Disable shadow build configuration in the project settings.
  - Add copy file (for Debug build):
    - Source: `...\include\runtime_dependencies\libcurl.dll`
    - Target: `..\debug\libcurl.dll` 
  - Repeat the same process for the Release build.
  - Ensure the working directory for run is set to `\Eventures`.
  - Select: Build > Build Project "Eventures" (Ctrl + B).

### **Copy Qt Runtime Dependencies (For deployment):**
- Navigate to the executable directory:
    ```
    cd /path/to/project/Eventures
    ```
- Generate runtime dependencies with Qt Windows deploy executable:
    ```
    /path/to/Qt/6.5.2/msvc2019_64/bin/windeployqt.exe Eventures.exe
    ```

### **Running The Executable**
- Ensure the project is open in Qt Creator (Ctrl + O and navigate to Eventures.pro)
- Select: Build/Run (Ctrl + R)

## Project Setup with Command line
### **Compilation**
- Navigate to the project .qmake.stash file location:
    ```
    cd /path/to/project/Eventures
    ```
- Run QMake (_Ensure the QMake executable is in your path directory_):
    ```
    qmake
    ```
- Run Make:
    ```
    make
    ```

### **Copy Qt Runtime Dependencies (For Deployment):**
- Navigate to the executable directory:
    ```
    cd /path/to/project/Eventures
    ```
- Generate runtime dependencies with Qt Windows deploy executable:
    ```
    /path/to/Qt/6.5.2/msvc2019_64/bin/windeployqt.exe Eventures.exe
    ```

### **Running The Executable**
- <ins>Without generating runtime dependencies:</ins>
  - Navigate to the project runtime dependency folder:
    ```
    cd /path/to/project/Eventures/include/runtime_dependencies
    ```
  - Run the executable with respect to the filepath:
    ```
    ../../release/Eventures.exe
    ```

- <ins>Build with runtime dependencies in the active folder:</ins>
  - Navigate to the project release folder:
    ```
    cd /path/to/project/Eventures/release
    ```
  - Run the executable:
    ```
    ./Eventures.exe
    ```
## Discord
Join our Discord community to connect with other developers, ask questions, and get help with the project:
[Join Eventures Discord](https://discord.gg/YpR748V89w)

## Artifact Generation
The project's artifact generation is managed through the workflow defined in our GitHub Actions setup. Every time there's a new commit or pull request, the workflow automatically generates the necessary artifacts.

The workflow is triggered by events such as pushes to the repository or pull requests being created. It handles the compilation, testing, and other necessary steps to produce the final artifacts. This ensures that the project remains consistent and reproducible across different environments.

For more details on how the artifact generation workflow is set up, please refer to our [workflow.yml](/.github/workflows/workflow.yml) file.

## Target Audience
This application is aimed at university students who don't have the time or the knowledge of local events required to attend. This application has the potential to benefit many more than just the target audience; however, this is the group the application will cater to the most. Notably, the application will also serve as great aid to event organizers who wish to spread knowledge and awareness of their events.

## The Group
Contributors to the Eventures application participating in the Otago University COSC345 paper are as follows:
- Riley Flanagan
- Luke Piper
- Kristie Koorts
- Eszter Scarlett-Herbert

## Contributions
All contributions adhering to the specifications above from members of the public are warmly welcomed. However, they must be accepted as pull requests before being added. In addition, credit to the contributor will be added to the README unless otherwise specified.

