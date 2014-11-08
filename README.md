boost_ipc_ex
============

boost::interprocess examples for qmake


## Craft .pro files

1. create pro/*.pro files from src/*.cpp

```
$ ruby tools/myerb.rb
```

2. update boost_ipc_ex.pro

```
$ rake cog:pro
```
