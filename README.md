# Objectif

So_long est le premier projet graphique de l'ecole 42. Le but est de creer un petit jeu en 2D avec l'aide d'une bibliotheque fournie : 
la minilibx. Les competences a acquierir pour ce projet sont : La gestion de fenetre, la gestion des evenements, le choix des textures. 
Comme la majorite des projets du tronc commun de 42, il se fait en C ! 🥳

# Comment je test le jeu ? 

Super simplement ! Tu commences par clone le repo (jusqu'ici on se comprend).
Puis, pour plus de fun, je t'invite a lancer directement la version bonus.
```
$ make bonus
$ ./so_long_bonus map_bonus.ber
```
La fenetre de jeu s'ouvre et c'est parti ! Le but est de ramasser toutes les cerises et de se rendre a la prote de sorti sans toucher les mechants slimes !!!

![Screenshot from 2023-03-03 16-43-14](https://user-images.githubusercontent.com/84559833/222763526-7ca5171c-5da3-4640-95e1-87150890895e.png)


# On s'amuse

Si l'envie te prends, tu peux modifier ou creer des maps a ta guise dans un fichier .ber. Il faut toutefois qu'elles repondent aux criteres suivants : 
* La map doit etre entouree de mur -> 1
* Elle doit etre remplie -> 0
* Les items a collecter sont marques par la lettre -> C
* Il faut obligatoirement une sortie -> E 
* Il faut obligatoirement un point de depart pour le personnage -> P 
* Les slines sont marques par la lettre -> S 
