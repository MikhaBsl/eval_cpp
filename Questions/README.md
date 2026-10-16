# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?

Les étapes de compilations sont :

* La pré processing : cela prend en compte les #include et #define
* Compilation cpp to assembleur
* Assamblage assembleur to obj
* le link des éléments rassemblage des fichers pour exe 

2. What is the difference between a declaration and a definition?

Une déclaration, c'est le fait de prévenir de l'existance d'une entité au compilateur, "jexiste" alors que la définition c'est le fait d'implementer la declaration, création de l'enité et allouer la mémoire (diff entre .h et .cpp)

3. What is the difference between passing a parameter by value, by reference, and by pointer?

La valeur sera copier, donc ça n'affecte pas la val d'origine
La référence est la valeur réel de la variable (un alias), elle ne peut pas être null
Le pointeur est l'adresse mémoire de la variable, elle peut être nul

4. What is the difference between the stack and the heap?

La pile stocke de manière automatique et rapide mais son stockage est très limiter
Le tas sert a de l'allocution dynamique de donnée, dans un espace de stockage très grand, par contre elle est plus lente

5. What is the difference between struct and class in C++?

la seul différence est qu'une struct est par défaut public et une class private

6. What is the difference between the public, protected, and private access specifiers?

Public tout le monde peut avoir accècs
Private toute définition private est propre a la class
Protectid  toute définition est propre à la class et à ses enfants (héritage)

7. What is a pure virtual function? What effect does it have on a class?

Une function virtual pure est définit par un =0 qui veut dire qu'elle n'a pas d'implémentation. ce qui la rend abstraitre donc les enfants de la classe devront obligatoirement la redéfinir.

8. Briefly explain the diamond problem in multiple inheritance.

On a une classe A. B et C hérite de A. D hérite de B et de C.
Donc D va hérité de A via B et C, ce qui créer un double exemplaire. Donc on a une ambiguité.
Pour résoudre ça, il faut avoir de l'héritage virtuel comme class B : virtal public A donc le compilateur va créer qu'une copie de la classe A

9. Name the different containers studied in class and describe the strengths and weaknesses of each.

Array, Force taille fixe connu a la compilation, pas de mémoire sur le tas (pile) du coup c'est rapide. Faiblesse, on peut pas modifier la taille
List, Froce, très rapide et simple pour remove ou insérer des nouveaux éléments. Faiblesse, très cher en mémoire et pas possible d'utiliser les indices pour avoir accès a la valeur
Vector. Force, bonne gestion mémoire et rapide. Faiblesse, très lourd pour insérer ou remove, il faut tout copier pour décaler
Map / Dictionnaire. Force, recherche, insertion et remove très rapide grace au clef. Faiblesse, plus loins en mémoire et comme il y a un tri ça peut avoir des conséquences en perf.
Set. Force, echerche, insertion et remove très rapide grace au clef unique. Faiblesse, on peut pas modifier les valeurs associté donc faut supprimer et refaire, ce qui peut être vite couteux en mémoire et pas d'acces direct

10. For each of the following scenarios, identify the most appropriate container and justify your choice.

* You need to store the top ten scores in a game. The number of elements is known and will never change.
→ Array, comme on connait le nombre est fixe, l'array sera plus rapide à parcourir et suffit pour cette strucuture

* You need to manage a queue of tasks that must be executed in the order they arrive.
→ Queue, le principe est simple, premier arrivé, premier sortie. Ce qui permet de garder l'ordre de priorité

* You frequently need to insert and remove elements in the middle of a sequence.
→ list, l'avantage des lists et de pouvoir ajouter des éléments comme les retirer de manière très simple, 
pour la simple est bonne raison qu'il suffit de changer les pointeurs des valeurs adjacentes

* You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.
→ Set, comme on veut juste savoir si l'élement existe le set permet d'avoir des clées uniques avec un ordre indéfinis.

* You need to keep track of actions so that the most recent action can be undone before earlier actions.
→ Pile, principe de last in, first out, le dernier élément ajouté sera le premiers a sortir

* You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.
→ Vector, le vector est le plus rapide pour le parcours et la récupération. Vu que ce sont les opérations les plus fréquents, c'est le plus opti pour ça

* You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.
→ Map, la structure des dictionnaire est simple, ici, on a les étudiants en clés et leur note en valeur. Ce qui permet d'avoir toutes les notes des élèves d'un coup

