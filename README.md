## Getting Started
-   On target Linux machine...
    -   Install Intel VTune Profiler
        -   [Download page](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler-download.html)
        -   [YUM instructions](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler-download.html?operatingsystem=linux&distributions=yumpackagemanager)
    -   Build this app
        ```sh
        cmake -S testitt -B testitt/build \
            -DCMAKE_BUILD_TYPE=Release \
            -DCMAKE_PREFIX_PATH=/opt/intel/oneapi/vtune/latest/sdk

        cmake --build testitt/build
        ```
-   To profile it from a Mac:
    -   Install Intel VTune Profiler
        -   [Download page](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler-download.html)
    -   In the VTune GUI
        -   Make a new project
        -   In the Configure Analysis page...
            -   In the WHERE box...
                -   Pick `Remote Linux (SSH)`
                -   Set `SSH destination` like: `username@hostname`
                    -   you need to set username, even if your `~/.ssh/config` already defines it
                -   Set `VTune Profiler installation directory` like: `/opt/intel/oneapi/vtune/latest`
            -   In the WHAT box...
                -   Pick `Launch Application`
                -   Set `Application` like: `/home/username/dev/testitt/build/myapp`
            -   In the HOW box...
                -   Click the `+` in the top right corner
                    -   The [official instructions](https://www.intel.com/content/www/us/en/develop/documentation/vtune-help/top/api-support/instrumentation-and-tracing-technology-apis/basic-usage-and-configuration/viewing-itt-api-task-data.html) say it's a `...` button but on my machine it was a `+`
                    -   If you don't see either icon, click on the `Performance Snapshot` dropdowny things and see if that makes it appear
                -   Check the box: `Analyze tasks, events, and counters`
            -   Hit the `>` Play button
            -   Eventually the results show up. I don't know how to really analyze them yet!
