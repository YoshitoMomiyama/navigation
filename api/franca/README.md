---------------------------------------------------------------------------------------------------------------------------------
IMPORTANT NOTE
---------------------------------------------------------------------------------------------------------------------------------

Please note that the franca interfaces defined  in the fidl files contained in the current folder are still a draft.

The conversion of the navigation D-Bus interfaces into franca-IDL interfaces has not been completed yet.

The official GENIVI navigation interfaces are those defined in the D-Bus XML files.

---------------------------------------------------------------------------------------------------------------------------------
HOW TO GENERATE THE COMMON API FILES
---------------------------------------------------------------------------------------------------------------------------------
First you need to have generated the common api tools and the common api dbus tools.
For example, to generate the whole set of stubs:

```mkdir build```
```cd build```
```cmake -DCOMMONAPI_TOOL_DIR=<tools path> -DCOMMONAPI_DBUS_TOOL_DIR=<dbus tools path> ../```

To generate part of the stubs, for example the stubs for poi service:
```cmake -DCOMMONAPI_TOOL_DIR=<tools path> -DCOMMONAPI_DBUS_TOOL_DIR=<dbus tools path> ../
```