/*Redo Programming Exercise 16 of Chapter 4 so that all of the named constants are defined in a namespace.

A new author is in the process of negotiating a contract for a new romance novel. The publisher is offering three options. In the first option, the author is paid $5,000 upon 
delivery of the final manuscript and $20,000 when the novel is published. In the second option, the author is paid 12.5% of the net price of the novel for each copy of the 
novel sold. In the third option, the author is paid 10% of the net price for the first 4,000 copies sold, and 14% of the net price for the copies sold over 4,000. 
The author has some idea about the number of copies that will be sold and would like to have an estimate of the royalties generated under each option. 

Write a program that prompts the author to enter the net price of each copy of the novel and the estimated number of copies that will be sold. 
The program then outputs the royalties under each option and the best option the author could choose. (Use appropriate named constants to store the special values 
such as royalty rates and fixed royalties.)

*/


#include <iostream>

using namespace std;

//first option, the author is paid $5,000 upon delivery of the final manuscript and $20,000 when the novel is published.
namespace firstOption 
{
    const int uponDelivery = 5000;
    const int whenPublished = 20000;
    int authorPaid = uponDelivery + whenPublished;
}
//second option, the author is paid 12.5% of the net price of the novel for each copy of the novel sold.
namespace secondOption
{
    double rate = 0.125;
    double royaltyCalc(double netPrice, int numCopiesSold) 
    {
        return (rate * netPrice) * numCopiesSold;
    }
}
//third option, the author is paid 10% of the net price for the first 4,000 copies sold, and 14% of the net price for the copies sold over 4,000.
namespace thirdOption
{
    double royaltyCalc(double netPrice, int numCopiesSold)
    {
        double authorPaid = 0;
        double overFourThousand = 0;
        double firstRate = 0.10;
        double secondRate = 0.14;

        if (numCopiesSold <= 4000) {
            authorPaid = (firstRate * netPrice) * numCopiesSold;
        }
        else {
            overFourThousand = numCopiesSold - 4000;
            authorPaid = ((secondRate * netPrice) * overFourThousand) + (firstRate * netPrice * 4000);
        }

        return authorPaid;
    }
}



int main()
{
    double netPrice;
    int numCopiesSold;
    cout << "Enter the net price of each copy of the novel: " ;
    cin >> netPrice;

    cout << "Enter the estimated number of copies that will be sold: " ;
    cin >> numCopiesSold;
    

    //The program then outputs the royalties under each option
    //calculate royalities
    double royaltiesFirstOption = firstOption::authorPaid;
    double royaltiesSecondOption = secondOption::royaltyCalc(netPrice, numCopiesSold);
    double royaltiesThirdOption = thirdOption::royaltyCalc(netPrice, numCopiesSold);

    cout << "Royalties:" << endl;
    cout << "1st Option: $" << royaltiesFirstOption << endl;
    cout << "2nd Option: $" << royaltiesSecondOption << endl;
    cout << "3rd Option: $" << royaltiesThirdOption << endl;

    //output the best option the author could choose.
    if ((royaltiesFirstOption >= royaltiesSecondOption) && (royaltiesFirstOption >= royaltiesThirdOption)) 
    {
        cout << "Best Option: 1st Option" << endl;
    }
    else if ((royaltiesSecondOption >= royaltiesFirstOption) && (royaltiesSecondOption >= royaltiesThirdOption)) 
    {
        cout << "Best Option: 2nd Option" << endl;
    }
    else
    {
        cout << "Best Option: 3rd Option" << endl;
    }

    return 0;
}