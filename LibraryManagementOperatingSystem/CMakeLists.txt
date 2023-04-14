PROJECT(LIBSIM)

ADD_EXECUTABLE(libsim AbstractUser.hpp Book.hpp Reader.hpp Manager.hpp "command.hpp" LibManageOS.h LibManageOS.cpp main.cpp)
