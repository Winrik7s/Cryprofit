**Profit calculation program*

(MSVC) С++ - Cryprofit.
=====================

<GITHUB></GITHUB>

***If you have ever invested in cryptocurrency, you were probably curious about how mush profit you made from selling certain tokens. Good news: **Cryprofit** will help you with this!***

***If you don't want to search for information and calculate on paper by yourself, then **Cryprofit** will be an excellent tool for you investment start!***

Quick start
=====================

- Download the [latest version from the releases page](https://github.com/Winrik7s/Cryprofit/releases/tag/0.1.0rc1), unzip the file and run the **Cryprofit.exe** application.

>**Attention!** You should not delete, move `libcurl-x64.dll` file
>>Run **Cryprofit.exe** from the same folder where the `libcurl-x64.dll` file is located
 
How to use it?
=====================

1. Clone this repository to your computer.
   - Go to the [cURL](https://curl.se/download.html#Win64) website and download one of the available binaries that corresponds to your system.
   - Extract the folder with the files to a convenient location on your computer.
2. Open `Cryprofit.sln` in **Visual Studio**.
   - Go to the project properties through the **Solution Explorer**.
   - In the **C/C++ section => General => Additional Include Directories**, paste the path to the `include` folder.
   - In the **Linker section => General => Additional Library Directories**, paste the path to the `lib` folder.
   - In the **Linker section => Input => Additional Dependencies**, paste the path to the `libcurl.dll.a` file. It should be located in the lib folder.
3. In the x64 => Release folder, place the `libcurl-x64.dll` file. Build the project. ***Done! Well done!***

***
![](img/_Image_github.png)
***
**#gdlck!**
