################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Controleur/Controleur.cpp 

OBJS += \
./Controleur/Controleur.o 

CPP_DEPS += \
./Controleur/Controleur.d 


# Each subdirectory must supply rules for building sources it contributes
Controleur/%.o: ../Controleur/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


