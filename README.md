# WebResults
Simple HTML Text Generator Using C

### Input
```c

int main() {

    clock_t startTime = 0;
    double* hunidFidy = (double*)calloc(1000, sizeof(double));

    for (int i = 0; i < 1000; i++) {
        hunidFidy[i] = (float)i;
        printf("%f ", hunidFidy[i]);
    }

    clock_t endTime = clock() - startTime;

    char buffer[3][200] = {
        "",
        "\t Job: Allocate 1000 Doubles",
        "\t Job: Set Index And Print Value Of All 1000 Doubles",
    };
    sprintf(buffer[0], "Time To Allocate 1000 Doubles: %i", endTime);

    WebResults results = CreateWebResults(10);
    AddNewResult(&results, buffer[0], strlen(buffer[0]));
    AddNewResult(&results, buffer[1], strlen(buffer[1]));
    AddNewResult(&results, buffer[2], strlen(buffer[2]));
    WriteWebResults(&results, "D:\\WebResults\\test.html");


    return 0;
}
```

### Output
![Generated Website](https://github.com/Bryson-C/WebResults/blob/main/Results.png)
