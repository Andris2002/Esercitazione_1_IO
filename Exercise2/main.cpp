#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

double mapping(double number){

    number = number*3/4. - 7./4.;
    return number;

}

int main()
{
    string path = "data.csv";
    ifstream ifs(path);
    ofstream ofs("result.csv");
    if (ifs.is_open()){
        double mean;
        double counter = 1;
        double data;

        while(!ifs.eof()){

            ifs >> data;
            cout << data << " ";
            double result = mapping(data);
            cout<< result << " ";
            if (counter-1){
                mean = (mean*(counter - 1) + result)/counter;

            }
            else {
                mean = result;
            }
            cout << mean << " " << counter << "\n";



            if (ofs.is_open()){
                ofs << mean << "\n";
            }
            ++counter;

        }
    }
    return 0;
}
