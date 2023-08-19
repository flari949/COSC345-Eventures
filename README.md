[![C/C++ CI](https://github.com/flari949/COSC345-Eventures/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/flari949/COSC345-Eventures/actions/workflows/c-cpp.yml)
[![Codacy Analysis CLI](https://github.com/flari949/COSC345-Eventures/actions/workflows/codacy-analysis.yaml/badge.svg)](https://github.com/flari949/COSC345-Eventures/actions/workflows/codacy-analysis.yaml)
# COSC345-Project
 
## Prerequisites:
Before compiling and running the project, make sure you have the following software installed and set up on your system:
1. **Visual Studio Code with C/C++ Extension:**
   - [Download Visual Studio Code](https://code.visualstudio.com/)
   - Install the "C/C++" extension from the Extensions Marketplace.

2. **MSYS2 with Required Packages:**
   - [Download MSYS2](https://www.msys2.org/)
   - Install MSYS2 using the installer (choose 64-bit version).
   - Launch "MSYS2 MSYS" terminal and update core packages:
     ```
     pacman -Syu
     ```
   - Install required build tools:
     ```
     pacman -S base-devel
     ```
3. **MINGW64:**
   - Open the "MSYS2 MinGW 64-bit" terminal and update package database:
     ```
     pacman -Syu
     ```
   - Install MINGW64:
     ```
     pacman -S mingw-w64-x86_64-toolchain
     ```
4. **GNU Make:**
   - If not installed, install `make`:
     ```
     pacman -S make
     ```
## Compiling the Project
1. **Clone the Repository:**
   - Open a terminal and navigate to your preferred directory.
   - Clone the repository:
     ```
     git clone https://github.com/flari949/COSC345-Eventures.git
     ```

2. **Compile the Project:**
   - Open the "MSYS2 MinGW 64-bit" terminal.
   - Navigate to the project directory:
     ```
     cd /path/to/project/COSC345-Eventures
     ```
   - Build the project:
     ```
     make
     ```

## Running the Project
1. **Run the Executable:**
   - Make sure you're in the project base folder.
   - Run the compiled application:
     ```
     ./app.exe
     ```

### About The Project
The Eventures application project is a group project for the COSC345 university paper at the University Of Otago. The purpose of this project is to design and create a useful application for the betterment of a user or society with the primary programming language as C/C++. The project requires the incorperation of two or more publicly available datasets (of different data domains) that can be combined to create additional meaning.

### Eventures
Eventures aims to combine [EventFinda](eventfinda.co.nz) event data along with [Land Information New Zealand](https://data.linz.govt.nz) geographical map data to superimpose event data on a visual interface for a unique and useful exploration and discovery application.

#### Target Audience
This application is aimed toward university students who don't have the time or the knowledge of local events required to attend. This application has the potential to benefit many more than just the target audience however this is the group the application will cater toward the most. Notably, the application will also serve to be of great aid to event organisers who wish to spread knowledge and awareness of their events.

#### The Group
Contributors to the Eventures application participating in the Otago University COSC345 paper are as below:
- Riley Flanagan
- Luke Piper
- Kristie Koorts
- Eszter Scarlett - Herbert


# Contributions
All contributions adhering to the specifications above from members of the puplic warmly welcomed, however must be accepted as pull requests before being added. On addition, credit to the contributor will be added in the README unless otherwise specified.
