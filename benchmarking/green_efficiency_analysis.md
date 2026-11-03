# Méthodologie de mesure
L'ensemble des tests a été réalisé sur un CPU Intel(R) Core(TM) Ultra 7 265K (2+8+10) @ 4.60 GHz, dans un conteneur Docker sous Ubuntu 24.04 
Les mesures sont basées sur le temps extrait à partir des cycles CPU via la fonction clock dans un programme C.
Chaque programme a été exécuté 3 fois afin de vérifier la stabilité des résultats, puis une moyenne des temps a été calculée pour chaque algorithme.

# Différences de performance observées
On voit clairement l'impact de différents algorithmes menant au même résultat. La tâche 1 en est l'exemple le plus frappant.
Sur 3 exécutions, nous avons constaté un énorme écart de performance entre les deux algorithmes ; l'algorithme naïf est 24 000 fois moins efficace que l'algorithme Single-pass.
En moyenne, l'algorithme naïf met 0,480 seconde à s'exécuter, alors que l'algorithme Single-pass ne met que 0,000020 seconde.
L'algorithme naïf répète inutilement des calculs en parcourant les données plusieurs fois, alors que le Single-pass ne les parcourt qu'une seule fois.

# Relation entre temps d'exécution et consommation d'énergie
Compte tenu des informations ci-dessus, il semble évident que l'impact sur la consommation d'énergie peut être massif, non seulement en puissance de calcul, mais aussi en temps de calcul et en chaleur générée qu'il faut ensuite refroidir.
En effet, l'énergie consommée dépend directement du temps pendant lequel le processeur travaille : plus un programme tourne longtemps, plus il consomme.
Même si ce grand écart de performance est invisible sur de petits programmes comme celui-ci, on peut imaginer l'importance d'optimiser les ressources pour des logiciels et services comptant des millions de clients et des milliards de processus.
Dans un data center, chaque seconde de calcul économisée réduit l'électricité et la climatisation nécessaires.

# Limites de l'expérience
Ces tests sont limités par la petite taille des processus, le faible nombre de tests et un environnement non contrôlé.
Le conteneur Docker et les autres programmes actifs sur la machine peuvent influencer les mesures.
Les temps très courts de l'algorithme Single-pass sont proches de la précision de la fonction clock, ce qui rend le ratio approximatif.
Enfin, la consommation d'énergie n'a pas été mesurée directement, elle est déduite du temps d'exécution.

# Enseignements pratiques pour l'ingénierie 
Cet exercice montre que l'ingénierie et les connaissances nécessaires pour concevoir des algorithmes efficaces sont essentielles. 
Cela permet d'économiser des ressources, pour des logiciels plus verts.
Optimiser le temps de calcul pour plus d'efficacité et une meilleure scalabilité.
Effet secondaire appréciable : cela donne un code clair, plus facile à lire et à maintenir. 
Avant de chercher à optimiser un programme, il est donc important de mesurer, d'identifier les parties les plus coûteuses et de réfléchir au choix de l'algorithme.
