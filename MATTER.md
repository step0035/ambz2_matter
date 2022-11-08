# Matter (previously CHIP) on AmebaZ2

## How to support Matter on Ameba SDK

https://github.com/xshuqun/ambz2_sdk/blob/matter/CHANGELOG.md

## Get Ameba SDK & Matter SDK

    Tested on Ubuntu 20.04
       
Create and enter new directory
    
    mkdir dev
    cd dev

To check out AmebaZ2 repository:

    git clone -b matter https://github.com/xshuqun/ambz2_sdk.git
    
To check out Matter repository:

    git clone -b v1.0-branch --recurse-submodules https://github.com/project-chip/connectedhomeip

Make sure ambz2_sdk and connectedhomeip are on the same directory level

    dev/
	├── ambz2_sdk
	└── connectedhomeip
	
## Set Matter Build Environment 

    > Find more details to setup linux build environment
    > https://github.com/project-chip/connectedhomeip/blob/master/docs/guides/BUILDING.md
    
    cd connectedhomeip

    source scripts/bootstrap.sh

    source scripts/activate.sh

## Make CHIP library by gn and Make lib_main.a
### all-clusters-app

    cd ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE

    source ToolPath.sh
	
    make all_cluster

### lighting-app

    cd ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE

    source ToolPath.sh

    make light
    
### switch-app

    cd ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE

    source ToolPath.sh

    make switch
    
### ota-requestor-app

    cd ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE

    source ToolPath.sh

    make otar

### CHIP core (generated by GN/ninja in connectedhomeip. Configured by [lib_chip.mk](https://github.com/hank820/ambz2_sdk/blob/matter/project/realtek_amebaz2_v0_example/GCC-RELEASE/lib_chip.mk))

    output : ambz2_sdk/component/soc/realtek/8710c/misc/bsp/lib/common/GCC
	
    > libCHIP.a

### CHIP application (generated and configured by [lib_chip_main.mk](https://github.com/hank820/ambz2_sdk/blob/matter/project/realtek_amebaz2_v0_example/GCC-RELEASE/lib_chip_main.mk)))

    output : ambz2_sdk/component/soc/realtek/8710c/misc/bsp/lib/common/GCC

    > lib_main.a

## Make Ameba application

    cd ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE

    make is_matter

## Flash Image

The generated image is found in ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE/application_is/Debug/bin/flash_is.bin

Method 1:

- Find more detail in [application_note](https://github.com/hank820/ambz2_sdk/blob/matter/doc/AN0500%20Realtek%20Ameba-ZII%20application%20note.en.pdf) Chapter4

Method 2 (using image tool and flashing script):

- Follow the Image Tool [README](https://github.com/hank820/ambz2_sdk/tree/v1.0-branch/tools/AmebaZ2/Image_Tool_Linux)

## Run CHIP task on AmebaZ2 (all-cluster-app/lighting-app/ota-requestor-app example)

	Matter task will auto start after reset the device.

## Test with [chip-tool](https://github.com/project-chip/connectedhomeip/tree/master/examples/chip-tool)
Use standalone chip-tool app(linux) to communicate with the device.

In order to send commands to a device, the device must be commissioned into the Matter network. The configuration state for chip-tool is stored in `/tmp/chip_tool_config.ini`; deleting this and other `.ini` files in `/tmp` can sometimes resolve issues due to stale configuration.

### Commission a device over BLE-WiFi

* Run CHIP-TOOL ble-wifi commissioning command `./chip-tool pairing ble-wifi <NODE_ID> <SSID> <PASSWORD> 20202021 3840`
* For example: `./chip-tool pairing ble-wifi 12344321 testssid password 20202021 3840`

### Commission a device over IP (For devices already on the WiFi network)

* Connect Ameba to AP using `ATW0, ATW1, ATWC` commands
* Run CHIP-TOOL onnetwork commissioning command `./chip-tool pairing onnetwork <NODE_ID> 20202021`
* For example: `./chip-tool pairing onnetwork 12344321 20202021`

### Command for onoff cluster

Use PA_20 as output, connect a LED to this pin and GND.

* Run CHIP-TOOL on-off cluster command `./chip-tool onoff on 12344321 1`

* Run CHIP-TOOL on-off cluster command `./chip-tool onoff off 12344321 1`


Find more detail in [chip-tool](https://github.com/hank820/connectedhomeip/tree/master/examples/chip-tool)

## Test with [Android Chip-Tool](https://github.com/hank820/connectedhomeip/tree/master/src/android/CHIPTool)

### Install Android Studio
* Download [Android Studio](https://developer.android.com/studio?gclid=Cj0KCQjwkIGKBhCxARIsAINMioLrotRhWXySwLrveax_JTX-qt1H-zjyGBEZk2FtseA-SYmQYmpq9M4aApGsEALw_wcB&gclsrc=aw.ds#downloads) and [Android-NDK-r21e](https://github.com/android/ndk/wiki/Unsupported-Downloads) and extract the files.
* Launch Android Studio: `cd android-studio/bin` and run `./studio.sh`
* Go to **Customize** and **All settings**. Under **Appearance & Behaviour** >> **System Settings** >> **Android SDK**, Check **Android 5.0 (Lollipop)** and uncheck the rest. Default Android SDK location is at `~/Android/Sdk`.

### Preparing for build

Run the following commands

	cd connectedhomeip/
	source script/bootstrap.sh
	export ANDROID_HOME=~/Android/Sdk
	export ANDROID_NDK_HOME={path to android-ndk-r21e}
	
Target CPU
`TARGET_CPU` can have the following values, depending on your smartphone CPU
architecture:

| ABI         | TARGET_CPU |
| ----------- | ---------- |
| armeabi-v7a | arm        |
| arm64-v8a   | arm64      |
| x86         | x86        |
| x86_64      | x64        |

Complete the following steps to prepare the Matter build:

1. Check out the Matter repository.

2. Run bootstrap (**only required first time**)

    ```shell
    source scripts/bootstrap.sh
    ```

3. Choose how you want to build the Android CHIPTool. There are **two** ways:
   from script, or from source within Android Studio.

<a name="building-scripts"></a>

### Building Android CHIPTool from scripts

This is the simplest option. In the command line, run the following command from
the top CHIP directory:

```shell
./scripts/build/build_examples.py --target android-arm64-chip-tool build
```
Note: It has been noticed that this step may fail on the first try, but running the second time will successfully build the apk.

See the table above for other values of `TARGET_CPU`.

The debug Android package `app-debug.apk` will be generated at
`out/android-$TARGET_CPU-chip-tool/outputs/apk/debug/`, and can be installed
with

```shell
adb install out/android-$TARGET_CPU-chip-tool/outputs/apk/debug/app-debug.apk
```

You can use Android Studio to edit the Android CHIPTool app itself and run it
after build_examples.py, but you will not be able to edit Matter Android code
from `src/controller/java`, or other Matter C++ code within Android Studio.

<a name="building-studio"></a>

### Building Android CHIPTool from Android Studio

This option allows Android Studio to build the core Matter code from source,
which allows us to directly edit core Matter code in-IDE.

1. In the command line, run the following command from the top Matter directory:

    ```shell
    TARGET_CPU=arm64 ./scripts/examples/android_app_ide.sh
    ```

    See the table above for other values of `TARGET_CPU`.

2. Modify the `matterSdkSourceBuild` variable to true, `matterBuildSrcDir` point
   to the appropriate output directory (e.g. `../../../../out/android_arm64`),
   and `matterSourceBuildAbiFilters` to the desired ABIs in
   [src/android/CHIPTool/gradle.properties](https://github.com/project-chip/connectedhomeip/blob/master/src/android/CHIPTool/gradle.properties)

3) Open the project in Android Studio and run **Sync Project with Gradle
   Files**.

4) Use one of the following options to build an Android package:

    - Click **Make Project** in Android Studio.
    - Run the following command in the command line:

        ```shell
        cd src/android/CHIPTool
        ./gradlew build
        ```

The debug Android package `app-debug.apk` will be generated at
`src/android/CHIPTool/app/build/outputs/apk/debug/`, and can be installed with

```shell
adb install src/android/CHIPTool/app/build/outputs/apk/debug/app-debug.apk
```

or

```shell
(cd src/android/CHIPTool && ./gradlew installDebug)
```

### BLE Commissioning
* Power on device and wait matter task run
* Launch Android Chip-Tool app and press **Provision CHIP Device With Wi-Fi**
* Scan the QR Code and enter the network credentials of the AP

Note: The QR code will be provided when booting, for example:
```shell
chip[SVR] SetupQRCode: [MT:-24J042C00KA0648G00]
chip[SVR] Copy/paste the below URL in a browser to see the QR Code:
chip[SVR] https://dhrishi.github.io/connectedhomeip/qrcode.html?data=MT%3A-24J042C00KA0648G00
```
Copy/paste the URL in a browser and a scannable QR code will be displayed.