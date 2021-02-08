/**
 * focaccia.cpp
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * EECS 183: Project 1
 * Fall 2020
 *
 * Project UID: 302fa9f14bd8266589c43c3129048565d11aa124
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */

int bottles_of_olive_oil(int loaves);
int cannisters_of_salt(int loaves);
int packages_of_yeast(int loaves);
int bags_of_flour(int loaves);
int loaves(int people);
double cost_of_ingredients(int bg, int p, int c, int bo);
string pluralize(string singular, string plural, int number);

int bottles_of_olive_oil(int loaves) {
  const double BOTTLES_PER_LOAF = 0.0592;
  int bottles = ceil(loaves * BOTTLES_PER_LOAF);

  return bottles;
}

int cannisters_of_salt(int loaves) {
  const double CANS_PER_LOAF = 0.3125;
  int cans = ceil(loaves * CANS_PER_LOAF);

  return cans;
}

int packages_of_yeast(int loaves) {
  const double PACKS_PER_LOAF = 7.0 / 9.0;
  int packs = ceil(loaves * PACKS_PER_LOAF);

  return packs;
}

int bags_of_flour(int loaves) {
  const double BAGS_PER_LOAF = 0.25;
  int bags = ceil(loaves * BAGS_PER_LOAF);

  return bags;
}

int loaves_(int people) {
  const double PEOPLE_PER_LOAF = 4.0;
  int loaves = ceil(people / PEOPLE_PER_LOAF);

  return loaves;
}

double cost_of_ingredients(int bg, int p, int c, int bo) {
  double cost = (2.69 * bg) + (0.40 * p) + (0.49 * c) + (6.39 * bo);

  return cost;
}

int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    // ---> your code here <---
    int loaves = loaves_(people);
    int bags = bags_of_flour(loaves);
    int packs = packages_of_yeast(loaves);
    int cans = cannisters_of_salt(loaves);
    int bottles = bottles_of_olive_oil(loaves);
    double cost = cost_of_ingredients(bags, packs, cans, bottles);

    cout << "You need to make: " << loaves << " " << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl;
    cout << "\nShopping List for Focaccia Bread \n--------------------------------" << endl;
    cout <<  bags << " " << pluralize("bag", "bags", bags) << " of flour" << endl;
    cout <<  packs << " " << pluralize("package", "packages", packs) << " of yeast" << endl;
    cout <<  cans << " " << pluralize("cannister", "cannisters", cans) << " of salt" << endl;
    cout <<  bottles << " " << pluralize("bottle", "bottles", bottles) << " of olive oil" << endl;
    cout << "\nTotal expected cost of ingredients: $" << cost << endl;
    cout << "\nHave a great socially-distanced party!" << endl;

    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
