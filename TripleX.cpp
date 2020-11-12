#include<iostream>
#include<ctime>

const int MaxDifficulty = 5;
void PrintIntroduction(int Difficulty)
{
    std::cout <<"\n\nYou are a secret agent breaking into a \n"<< Difficulty;
    std::cout << " secure server room... Enter the correct code to continue...\n\n";                               
                   
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    


    //Declare 3 number code
    const int CodeA = rand()%Difficulty + Difficulty;
    const int CodeB = rand()%Difficulty + Difficulty;
    const int CodeC = rand()%Difficulty + Difficulty;

  

    const int CodeSum = CodeA + CodeB + CodeC ;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    //print sum and product
    std::cout << std::endl; 
    std::cout << "-The codes multiply to give:\n" ;
    std::cout << "\n-The codes add up to: " << CodeSum;
    std::cout << "\n-The codes multiply up to: "<< CodeProduct;

    //Store Player guess
    int GuessA, GuessB, GuessC;
    std::cout << "\n";
    std::cin >> GuessA >> GuessB >> GuessC ;
    
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    //Check if the players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou Win";

        if(Difficulty < MaxDifficulty)
        {
            std::cout << "\nMoving to next level ";
        }
        return true;
    }
    else
    {
        std::cout << "\nYou Lost!";
        std::cout << "\n Thats' not quite right try again";
        return false;
    }
    

}

int main()
{
    srand(time(NULL)); // create new random sequence based on the time of the day
    int LevelDifficulty = 1;
    
    while(LevelDifficulty <= MaxDifficulty) // lopp the game until MaxDifficulty
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear(); //clear the errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete)
        {
            //incerease the level difficulty
            ++LevelDifficulty;
        }
    }
    
    std::cout<< "\n*** Great work agent! You got all the files! Now get out of there!*** \n";
    return 0;
}