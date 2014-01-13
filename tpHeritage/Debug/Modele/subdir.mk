################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modele/Cercle.cpp \
../Modele/ElementGeo.cpp \
../Modele/Groupe.cpp \
../Modele/Ligne.cpp \
../Modele/Modele.cpp \
../Modele/Point.cpp \
../Modele/PolyLigne.cpp \
../Modele/Rectangle.cpp 

OBJS += \
./Modele/Cercle.o \
./Modele/ElementGeo.o \
./Modele/Groupe.o \
./Modele/Ligne.o \
./Modele/Modele.o \
./Modele/Point.o \
./Modele/PolyLigne.o \
./Modele/Rectangle.o 

CPP_DEPS += \
./Modele/Cercle.d \
./Modele/ElementGeo.d \
./Modele/Groupe.d \
./Modele/Ligne.d \
./Modele/Modele.d \
./Modele/Point.d \
./Modele/PolyLigne.d \
./Modele/Rectangle.d 


# Each subdirectory must supply rules for building sources it contributes
Modele/%.o: ../Modele/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


