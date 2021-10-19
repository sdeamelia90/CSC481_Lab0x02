#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <stdlib.h> 

void doBusyWork() {
    for (int k = 0; k < 20; k++) {
        // Constant N
    }
}

void busyyAlgorithm_N3(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                doBusyWork();
            }
        } 
    }
}

void busyyAlgorithm_NlogN(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j = j * 2) {
            doBusyWork();
        }
    }
}

void busyAlgorithm_logN(int N) {
    if (N > 1) {
        busyAlgorithm_logN(N / 2);
    }

    doBusyWork();
}

void busyAlgorithm_N2logN(int N) {
    if (N > 1) {
        busyAlgorithm_N2logN(N / 2);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            doBusyWork();
        }
    }
}

void busyAlgorithm_N6(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            for (int k = 0; k < N + 1 ; k++) {
                for (int l = 0; l < N + 1; l++) {
                    for (int m = 0; m < N + 1; m++) {
                        for (int n = 0; n < N + 1; n++) {
                            doBusyWork();
                        }
                    }
                }
            }
        }
    }
}

void busyAlgorithm_logN_squared(int N) {
        
        if (N > 1) {
            if (N > 1) {
                busyAlgorithm_logN_squared(N * .75);
            }
        }

    doBusyWork();
}

void busyAlgorithm_exp(N) {
    for(int i = 0; i < N; i++) {
        busyAlgorithm_exp(i);

    }
    doBusyWork();
}

void busyyAlgorithm_factorial(N) {
    for (int i = 0; i < N; i++) {
        busyAlgorithm_exp(i + 1);
    }
    doBusyWork();
}

void printTable(int timeCount, double TIME[], int sort) {
    printf("%12s %16s %14s %14s\n", "  N  ", "Measured Time(s)", "Dbling Ratio", "Expected Ratio");
    printf("        ====================================================\n");
    double n = 2;
    double doubleRatio = 0;
    double theoryRatio = 0;
    printf("%12d %12lf\n", 1, TIME[0]);

    for (int i = 1; i < timeCount; i++) {
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
            theoryRatio = pow(2,n);
        }
        else if (sort == 8) {
            theoryRatio = 0;;
        }
        printf("%12d %12lf %12.2lf %12.2lf\n", (int)n, TIME[i], doubleRatio, theoryRatio);
        n = n * 2;
    }
}

int main(int argc, int argv) {

    double trialsTime_max = .250; // in seconds 

    long long int trialsCount_max = 10000, // increase as needed to avoid time measurements of zero 
        N_min = 1,
        N_max = 10000000, // adjust as needed, keep small for debugging 
        n, 
        trial;

    clock_t splitTimeStamp, 
        trialSetStart;

    double splitTime, 
        trialSetCount, 
        trialSetTime, 
        dummySetCount, 
        dummySetTime, 
        averageTrialTime, 
        averageDummyTrialTime, 
        estimatedTimePerTrial;

    double timeArr[1000] = { 0 };

    int timeCount = 0,
        sort = 0;


    // If you are printing a results table directly, print your header line here. 



    // For each size N of input we want to test -- typically start N at 1 and double each repetition 

    for (n = 1; n < N_max; n = n * 2) {



        /********* any preparations, test input generation, to be used for entire trial set ********/


        splitTime = 0.0;

        // get timestamp before set of trials are run: 

        trialSetStart = clock();

        // For each trial trialNumber=1 to Number of Trials per input size: 

        for (trial = 0; trial < trialsCount_max && splitTime < trialsTime_max; trial++) {



            /******** any preparations, test input generation, for a single trial run *********/


            /**** >>>> Call the algorithm function we are testing, using the generated test input <<<<< ******/
            //busyyAlgorithm_N3(n); //1
            //busyyAlgorithm_NlogN(n);  //2
            //busyAlgorithm_logN(n); //3
            //busyAlgorithm_N2logN(n); //4
            //busyAlgorithm_N6(n);  //5
            busyAlgorithm_logN_squared(n); //6
            //busyAlgorithm_exp(n); //7
            //busyyAlgorithm_factorial(n); //8


            /******* do any "clean up" after running your algorithm ********/



            // get split time -- "split time" just means the total time so far for this tiral set 

            splitTimeStamp = clock(); //  

            // split time is the difference between current split timestamp and the starting time stamp for trial set 

            splitTime = (splitTimeStamp - (double)trialSetStart) / (double)CLOCKS_PER_SEC; // CLOCK_PER_SEC define time.h  

        }

        trialSetCount = (double)trial; // value of trial when loop ends is how many we did 

        trialSetTime = splitTime; // total time for trial set is the last split time 

        averageTrialTime = trialSetTime / trialSetCount; // this is the average tiem per trial, including any prep/overhead 

        /********* NOW DO A "DUMMY" TRIAL SET TO ESTIMATE THE OVERHEAD TIME ********/

        /* We can just repeat this trialSetCount times, which we know should be faster than above */



        splitTime = 0.0;

        // get timestamp before set of dummy trials are run: 

        trialSetStart = clock();

        for (trial = 0; trial < trialSetCount && splitTime < trialsTime_max; trial++) {



            /******** any preparations, test input generation, for a single trial run *********/

            doBusyWork();

            /**** DO NOT Call the algorithm function!!! ******/



            /******* do any "clean up" after running your algorithm ********/



            // get split time -- "split time" just means the total time so far for this tiral set 

            splitTimeStamp = clock(); //  

            // split time is the difference between current split timestamp and the starting time stamp for trial set 

            splitTime = (splitTimeStamp - (double)trialSetStart) / (double)CLOCKS_PER_SEC; // CLOCK_PER_SEC define time.h  

        }

        dummySetCount = (double)trial; // value of trial when loop ends is how many we did, should be same as trialsSetCount 

        dummySetTime = splitTime; // total time for dummy trial set is the last split time 

        averageDummyTrialTime = dummySetTime / dummySetCount; // this is the average tiem per dummy trial, including any prep/overhead 

        estimatedTimePerTrial = averageTrialTime - averageDummyTrialTime; // should be a decent measurement of time taken to run your algorithm 

        /************ save and/or print your results here to generate your table of results **************/

        // You should be able to print one row of your results table here. 

        // Calculate doubling ratios and any other results for desired columns in table. 

        // Consider additional columns you include in a more detailed table that may help with debugging or just making sense of results. 

        // May be a good idea to print a row of results to output terminal window or a file, so if your program crashes you still have results to look at 

        // use the fflush(stdout) or fflush(filePointer) or equivalent in C++, to force output so nothing is lost if a crash occurs 

        // can also save data to array(s) for later printing/processing 

        timeArr[timeCount] = estimatedTimePerTrial;
        timeCount++;
    }
    printTable(timeCount, timeArr, 6);

}