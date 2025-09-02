<header>GCC et le langage C:</header>

<h1>Que signifie GCC ?</h1>
GCC veut dire GNU Compiler Collection. C’est un programme qui traduit le code C (et d’autres langages) en langage machine que l’ordinateur peut exécuter.

<h1>Que signifie GNU ?</h1>
GNU veut dire GNU’s Not Unix. C’est un projet de logiciel libre qui ressemble à Unix mais qui est gratuit et ouvert à tous.

<h1>Quel est le problème avec GCC ?</h1>
Il n’y a pas vraiment de problème technique. GCC est fiable et puissant. La seule chose, c’est qu’il est sous licence GPL, ce qui impose certaines règles pour ceux qui veulent faire du logiciel propriétaire.

<h1>Comment GCC aide-t-il à trouver des erreurs ?</h1>
Quand tu compiles avec GCC, il affiche des messages d’erreurs et d’avertissements pour signaler les fautes dans ton programme (comme des variables non utilisées, mauvaises conversions, etc.).

<h1>Pourquoi la syntaxe de C est-elle si concise ?</h1>
Le langage C utilise des mots courts et des symboles (comme { } au lieu de begin et end) pour écrire moins et aller plus vite.

<h1>Dans main, exit(0) et return 0 sont-ils équivalents ?</h1>
Oui, dans la fonction main, les deux arrêtent le programme normalement et indiquent que tout s’est bien passé. La différence est technique, mais pour l’apprenant, c’est la même chose.

<h1>Que se passe-t-il si on atteint la fin de main sans return ?</h1>
En C moderne (C99 et après), si on oublie return 0;, le programme renvoie automatiquement 0, donc pas d’erreur.

<h1>Le compilateur supprime-t-il les commentaires ou les remplace-t-il par des espaces ?</h1>
Il supprime le texte des commentaires, mais laisse un espace à la place pour que le code reste correct.

<h1>Comment savoir si un commentaire n’est pas terminé ?</h1>
Le compilateur arrête la compilation et affiche une erreur « commentaire non terminé ».

<h1>Peut-on imbriquer un commentaire dans un autre ?</h1>
Non, en C on ne peut pas mettre un commentaire /* ... */ à l’intérieur d’un autre.

<h1>D’où vient le nom du type float ?</h1>
Il vient de floating-point, qui veut dire « nombre à virgule flottante » (un nombre avec une partie décimale).

<h1>Pourquoi les constantes à virgule flottante doivent-elles se terminer par f ?</h1>
Parce que par défaut, un nombre décimal est un double. Ajouter f (comme 3.14f) indique qu’on veut un float, qui est plus petit et plus précis pour certaines utilisations.