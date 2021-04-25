# CannyLine Pybind

# Usage
## requirements
```shell
sudo apt install cmake gcc g++ libopencv-dev pybind11-dev
```

## install
```shell
# install pybind11
git clone https://github.com/pybind/pybind11.git
mkdir build
cd build
cmake ..
make -j8
make install
```

```shell
# compile cannyline
python3 setup.py build
# Then move the *.so to your project, you can import the module directly.
```
## run
```
from cannyline import MetaLine
````


