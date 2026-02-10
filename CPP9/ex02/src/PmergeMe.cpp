#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <set>

// 1) Tri recursif pour trouver la main chain
// 2) On a notre liste de perdant des pairs du debut
// 3) on fait un coup gratuit, le perdant du plus petit gagnant dans les pairs du debut
// 4) Pour choisir les perdants a inserer on regarde la suite de jacobsthal, on prend un num de la suite en tant qu indice de notre liste de perdant 
// 5) on insere ce numero dans la main chain via binary search (FR = Recherche dicothomique) et on check sa pair du debut ou il est perdant pour limiter le champs de la recherche
// 6) on prend indice jacobsthal - 1 et on refait pareil sur l´insertion
// 7) ensuite on continue d inserer avec l indicde jachobstal de plus en plus petit jusqu a ne plus avoir de perdant

// Calcule récursivement le n-ième nombre de Jacobsthal.
size_t getJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

// Génère la séquence d'indices optimale pour l'insertion basée sur la suite de Jacobsthal.
template <typename Container>
Container generateJacobSeq(size_t n) {
    Container seq;
    size_t jacobIndex = 3;
    size_t lastJacob = 1;
    while (lastJacob < n) {
        size_t currentJacob = getJacobsthal(jacobIndex);
        for (size_t i = currentJacob; i > lastJacob; --i) {
            if (i <= n)
                seq.push_back(i);
        }
        lastJacob = currentJacob;
        jacobIndex++;
    }
    return seq;
}

// Trie un std::vector en utilisant l'algorithme Ford-Johnson (Merge-Insertion).
void sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    if (pairs.size() > 0) {
        std::vector<int> mainChain;
        for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);
        
        sortVector(mainChain);

        std::vector<std::pair<int, int> > sortedPairs;
        std::vector<int> pending;
        
        for (size_t i = 0; i < mainChain.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == mainChain[i]) {
                    sortedPairs.push_back(pairs[j]);
                    pending.push_back(pairs[j].second);
                    pairs.erase(pairs.begin() + j);
                    break;
                }
            }
        }
        
        arr = mainChain;
        arr.insert(arr.begin(), pending[0]);

        std::vector<size_t> jacobSeq = generateJacobSeq<std::vector<size_t> >(pending.size());
        
        for (size_t i = 0; i < jacobSeq.size(); ++i) {
            size_t idxInPending = jacobSeq[i] - 1;
            if (idxInPending < 1 || idxInPending >= pending.size()) continue;

            int objectToInsert = pending[idxInPending];
            std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), objectToInsert);
            arr.insert(pos, objectToInsert);
        }
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), straggler);
        arr.insert(pos, straggler);
    }
}

// Trie une std::deque en utilisant l'algorithme Ford-Johnson (Merge-Insertion).
void sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    if (pairs.size() > 0) {
        std::deque<int> mainChain;
        for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);
        
        sortDeque(mainChain);

        std::deque<std::pair<int, int> > sortedPairs;
        std::deque<int> pending;
        
        for (size_t i = 0; i < mainChain.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == mainChain[i]) {
                    sortedPairs.push_back(pairs[j]);
                    pending.push_back(pairs[j].second);
                    pairs.erase(pairs.begin() + j);
                    break;
                }
            }
        }
        
        arr = mainChain;
        arr.insert(arr.begin(), pending[0]);

        std::deque<size_t> jacobSeq = generateJacobSeq<std::deque<size_t> >(pending.size());
        
        for (size_t i = 0; i < jacobSeq.size(); ++i) {
            size_t idxInPending = jacobSeq[i] - 1;
            if (idxInPending < 1 || idxInPending >= pending.size()) continue;

            int objectToInsert = pending[idxInPending];
            std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), objectToInsert);
            arr.insert(pos, objectToInsert);
        }
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), straggler);
        arr.insert(pos, straggler);
    }
}

// Forme canonique de Coplien.
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const&) {}
PmergeMe& PmergeMe::operator=(PmergeMe const&) { return *this; }
PmergeMe::~PmergeMe() {}

// Gère le parsing des entrées, lance les tris et affiche les performances.
void PmergeMe::process(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return;
    }
    std::vector<int> vec;
    std::deque<int>  deq;
    std::set<int>    seen; 

    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        int value;
        if (!(ss >> value)) { std::cout << "Error" << std::endl; return; }
        if (value < 0 || seen.count(value)) { std::cout << "Error" << std::endl; return; }
        
        seen.insert(value);
        vec.push_back(value);
        deq.push_back(value);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? " " : "");
        if (i > 5 && vec.size() > 10) { std::cout << "[...]"; break; }
    }
    std::cout << std::endl;

    clock_t startVec = clock();
    sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sortDeque(deq);
    clock_t endDeq = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? " " : "");
        if (i > 5 && vec.size() > 10) { std::cout << "[...]"; break; }
    }
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}