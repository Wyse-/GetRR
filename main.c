#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main(){
    while(1){ // Endless loop
        DEVMODE* monitorProperties = NULL; // Initialize null DEVMODE pointer
        monitorProperties = (DEVMODE*)malloc(sizeof(DEVMODE)); // Dynamically allocate memory to the DEVMODE pointer
        EnumDisplaySettingsA(NULL, ENUM_CURRENT_SETTINGS, monitorProperties); // Call EnumDisplaySettings function (from windows.h)
        printf("Refresh rate: %d\n", monitorProperties->dmDisplayFrequency); // Print current refresh rate
        FILE *f = fopen("refreshRate.txt", "w"); // Open fine refreshRate.txt with write flag
        if (f == NULL){ // If unable to open file display an error.
            printf("Error opening file!\n");
            exit(1);
        }
        else{ // If no errors proceed and print the current refresh rate value to refreshRate.txt
            fprintf(f, "%d", monitorProperties->dmDisplayFrequency);
            fclose(f);
            Sleep(5000); // Wait for 5 seconds
        }
    }
    return 0;
}
