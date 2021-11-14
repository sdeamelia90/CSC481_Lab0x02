#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <stdlib.h> 

int BUSYCOUNT = 0;

void doBusyWork() {
    for (int k = 0; k < 300; k++) {
    }
    BUSYCOUNT++;
}

void busyyAlgorithm_N3(long long int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                doBusyWork();
            }
        } 
    }
}

void busyyAlgorithm_NlogN(long long int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j = j * 2) {
            doBusyWork();
        }
    }
}

void busyAlgorithm_logN(long long int N) {
    if (N > 1) {
        busyAlgorithm_logN(N / 2);
    }

    doBusyWork();
}

void busyAlgorithm_N2logN(long long int N) {
    if (N > 1) {
        busyAlgorithm_N2logN(N / 2);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            doBusyWork();
        }
    }
}

void busyAlgorithm_N6(long long int N) {
    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < N * 2; j++) {
            for (int k = 0; k < N * 2 ; k++) {
                for (int l = 0; l < N * 2; l++) {
                    for (int m = 0; m < N * 2; m++) {
                        for (int n = 0; n < N * 2; n++) {
                            doBusyWork();
                        }
                    }
                }
            }
        }
    }
}

void busyAlgorithm_logN_squared(int N) {
        
    for (int i = 1; i <= N; i = i * 2) {
        for (int j = 1; j <= N; j = j * 2) {
            doBusyWork();
        }
    }
}

void busyAlgorithm_exp(N) {

    if (N > 1) {
        busyAlgorithm_exp(N - 1);
        busyAlgorithm_exp(N - 1);
    }

    doBusyWork();
}

void busyyAlgorithm_factorial(N) {
    if (N > 1) {
        for (int i = 0; i < N; i++) {
            busyyAlgorithm_factorial(N - 1);
        }
    }
        doBusyWork();
}

void printTable(int timeCount, double TIME[], int busyCountArr[], int sort) {
    printf("%12s %14s %20s %16s %16s %14s %14s \n", "Power of 2", "  N  ", "Measured Time(s)", "Dbling Ratio", "Expected Ratio", "Busy Count", "MT / BC");
    printf("=================================================================================================================\n");
    double n = 2;
    double doubleRatio = 0;
    double theoryRatio = 0;
    double busyTimeZero = TIME[0] / busyCountArr[0];

    printf("%12d %12d %22.8lf %16s %16s %14d %14.8lf\n", 0, 1, TIME[0], "-", "-", busyCountArr[0], busyTimeZero);

    for (int i = 1; i < timeCount; i++) {
        double busyTime = TIME[i] / (double)busyCountArr[i];
        if ((TIME[i - 1] == 0) | (TIME[i - 1] == -0)) {
            doubleRatio = 0;
        }
        else {
            doubleRatio = TIME[i] / TIME[i - 1];
        }
        if (sort == 1) {
            theoryRatio = 8.0;
        }
        else if (sort == 2) {
            theoryRatio = 2 * log2(n) / (log2(n) - log2(2));
        }
        else if (sort == 3) {
            theoryRatio =  log2(n) / (log2(n) - log2(2));
        }
        else if (sort == 4) {
            theoryRatio = 4 * log2(n) / (log2(n) - log2(2));
        }
        else if (sort == 5) {
            theoryRatio = 64.0;
        }
        else if (sort == 6) {
            theoryRatio = (log2(n) * log2(n)) / (log2(n / 2) * log2(n / 2));
        }
        else if (sort == 7) {
            theoryRatio = pow(2,n) / pow(2, n/2);
        }
        else if (sort == 8) {
            theoryRatio = 0;;
        }
        printf("%12d %12lld %22.8lf %16.2lf %16.2lf %14d %14.8lf\n", i , (long long int)n, TIME[i], doubleRatio, theoryRatio, busyCountArr[i], busyTime);
        n = n * 2;
    }
}

void printTable2(int timeCount, double TIME[], int busyCountArr[], int sort) {
    printf("%14s %20s %16s %16s %14s %14s \n", "  N  ", "Measured Time(s)", "Dbling Ratio", "Expected Ratio", "Busy Count", "MT / BC");
    printf("=================================================================================================================\n");
    double n = 2;
    double doubleRatio = 0;
    double theoryRatio = 0;
    double busyTimeZero = TIME[0] / busyCountArr[0];

    printf("%12d %22.8lf %16s %16s %14d %14.8lf\n", 1, TIME[0], "-", "-", busyCountArr[0], busyTimeZero);

    for (int i = 1; i < timeCount; i++) {
        double busyTime = TIME[i] / (double)busyCountArr[i];
        if ((TIME[i - 1] == 0) | (TIME[i - 1] == -0)) {
            doubleRatio = 0;
        }
        else {
            doubleRatio = TIME[i] / TIME[i / 2];
        }

        if ((int)n % 2 == 0) {
            if (sort == 7) {
                theoryRatio = pow(2, n) / pow(2, n / 2);
            }
            else if (sort == 8) {
                double temp = 1;
                for (int i = 1; i <= n; i++) {
                    temp = temp * i;
                }
                double temp2 = 1;

                for (int i = 1; i <= n / 2; i++) {
                    temp2 = temp2 * i;
                }
                theoryRatio = temp / temp2;
            }

            printf("%12lld %22.8lf %16.2lf %16.2lf %14d %14.8lf\n", (long long int)n, TIME[i], doubleRatio, theoryRatio, busyCountArr[i], busyTime);
        }
        else {
            printf("%12lld %22.8lf %16s %16s %14d %14.8lf\n", (long long int)n, TIME[i], "-", "-", busyCountArr[i], busyTime);
        }

        n++;  //change for 1-6
    }
}

int main(int argc, int argv) {

    double trialsTime_max = .250; // in seconds 

    long long int trialsCount_max = 10000, // increase as needed to avoid time measurements of zero 
        N_min = 1,
        N_max = 26, // adjust as needed, keep small for debugging 
        n, 
        trial;

    clock_t splitTimeStamp, 
        trialSetStart;

    double splitTime,
        trialSetCount,
        trialSetTime,
        averageTrialTime;

    double timeArr[1000] = { 0 };
    int busyCountArr[1000] = { 0 };

    int timeCount = 0,
        sort = 0;

    for (n = 1; n < N_max; n++) {  //change for 1-6

        int busyCount = 0;
        splitTime = 0.0;
        trialSetStart = clock();

        for (trial = 0; trial < trialsCount_max && splitTime < trialsTime_max; trial++) {

            //busyyAlgorithm_N3(n); //1
            //busyyAlgorithm_NlogN(n);  //2
            //busyAlgorithm_logN(n); //3
            //busyAlgorithm_N2logN(n); //4
            //busyAlgorithm_N6(n);  //5
            //busyAlgorithm_logN_squared(n); //6
            busyAlgorithm_exp(n); //7
            //busyyAlgorithm_factorial(n); //8

            splitTimeStamp = clock(); //  
            splitTime = (splitTimeStamp - (double)trialSetStart) / (double)CLOCKS_PER_SEC; // CLOCK_PER_SEC define time.h  
            busyCountArr[timeCount] = BUSYCOUNT;
            BUSYCOUNT = 0;

        }

        trialSetCount = (double)trial; // value of trial when loop ends is how many we did 
        trialSetTime = splitTime; // total time for trial set is the last split time 
        averageTrialTime = trialSetTime / trialSetCount; // this is the average tiem per trial, including any prep/overhead 
        timeArr[timeCount] = averageTrialTime;
        timeCount++;
    }
    //printTable(timeCount, timeArr, busyCountArr, 7);
    printTable2(timeCount, timeArr, busyCountArr, 7);

}
