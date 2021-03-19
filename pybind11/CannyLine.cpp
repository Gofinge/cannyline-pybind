#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "np2mat/ndarray_converter.h"
#include "MetaLine.h"
namespace py = pybind11;

PYBIND11_MODULE(cannyline, m) {
    NDArrayConverter::init_numpy();
    py::class_<MetaLine>(m, "MetaLine")
            .def(py::init<>())
            .def_readwrite("p",&MetaLine::p)
            .def_readwrite("sigma",&MetaLine::sigma)
            .def_readwrite("thAngle",&MetaLine::thAngle)
            .def_readwrite("thGradientLow",&MetaLine::thGradientLow)
            .def_readwrite("thGradientHigh",&MetaLine::thGradientHigh)
            .def_readwrite("cannyEdge",&MetaLine::cannyEdge)
            .def("getInformations", &MetaLine::getInformations, py::arg("original_image"),
                 py::arg("gause_sigma")=1, py::arg("gause_half_size")=1, py::arg("p")=0.125)
            .def("line_detection", &MetaLine::MetaLineDetection, py::arg("original_image"),
                 py::arg("gause_sigma")=1, py::arg("gause_half_size")=1,
                 py::arg("lines")=std::vector<std::vector<float>>())
            ;
}
