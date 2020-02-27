cmake_minimum_required(VERSION 3.15)
project(HospitalDatabase)

set(CMAKE_CXX_STANDARD 14)

add_executable(HospitalDatabase main.cpp Person.h Person.cpp Patient.h Patient.cpp Billing.h Billing.cpp Doctor.h Doctor.cpp DatabaseImplementation.h)