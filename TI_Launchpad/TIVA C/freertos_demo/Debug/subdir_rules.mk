################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
freertos_demo.obj: ../freertos_demo.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.4/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.4/include" --include_path="C:/Users/Carlos  Belmonte/Desktop/TIVA C/Proyectos/freertos_demo" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/ek-tm4c123gxl" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/include" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --diag_warning=225 --display_error_number --diag_wrap=off --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="freertos_demo.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

led_task.obj: ../led_task.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.4/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.4/include" --include_path="C:/Users/Carlos  Belmonte/Desktop/TIVA C/Proyectos/freertos_demo" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/ek-tm4c123gxl" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/include" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --diag_warning=225 --display_error_number --diag_wrap=off --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="led_task.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup_ccs.obj: ../startup_ccs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.4/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.4/include" --include_path="C:/Users/Carlos  Belmonte/Desktop/TIVA C/Proyectos/freertos_demo" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/ek-tm4c123gxl" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/include" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --diag_warning=225 --display_error_number --diag_wrap=off --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

switch_task.obj: ../switch_task.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.4/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.4/include" --include_path="C:/Users/Carlos  Belmonte/Desktop/TIVA C/Proyectos/freertos_demo" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/ek-tm4c123gxl" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/include" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --diag_warning=225 --display_error_number --diag_wrap=off --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="switch_task.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


