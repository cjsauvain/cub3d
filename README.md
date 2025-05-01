# cub3d

> Projet en groupe réalisé dans le cadre du cursus de l’école 42.  

## 📌 Objectif

> Il s'agit d’un **mini moteur de rendu 3D** basé sur la technique du **raycasting**, inspiré de jeux comme *Wolfenstein 3D*.  
> Le joueur peut se déplacer dans un monde en pseudo-3D généré à partir d’une carte `.cub`.

## ✅ Prérequis

- Système Linux
- clang
- Bibliothèques : `mlx`, `X11`, `Xext`, `math.h`

## 📦 Compilation & 🚀 Exécution
```bash
make [bonus]

./cub3d maps/<map_name.ber>
```

## ⚙️ Fonctionnalités principales

- Parsing de fichiers `.cub` :
- Gestion des fenêtres
- Textures (`NO`, `SO`, `WE`, `EA`)
- Couleurs sol/plafond (`F`, `C`)
- Contrôles clavier :
  - `W`, `A`, `S`, `D` : mouvement
  - `←` / `→` : rotation
  - `ESC` : quitter
- Carte 2D en caractères :
  - `1` : Murs
  - `0` : Espace
  - `N`, `S`, `E`, `W` : Position et orientation initiale du joueur 
- Rendu 3D par **raycasting**
- Textures appliquées sur les murs
- Bonus :
  - minimap
  - portes
  - rotation point de vue avec la souris
  - sprites animés
  - collisions avec les murs
