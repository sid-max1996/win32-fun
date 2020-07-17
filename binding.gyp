{
    "targets": [{
        "target_name": "win32-fun",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions", "-lole32", "-loleaut32" ],
        "sources": [
            "src/main.cpp",
            "src/win32_fun.cpp",
            "src/diskusage.cpp",
            "src/screen.cpp",
            "src/audio.cpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
