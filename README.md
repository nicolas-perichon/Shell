**Projet Shell**  
**USSI2C**   
**BDIA3**

**Arthur Baribeaud**  
**Nicolas Perichon**  
**Paul Reversac**

# Shell

##Le mini shell embarque les builtins suivant :  
###cat : 
Prend en argument le nom du fichier à afficher  
 
###cd : 
Prend en argument le repertoire vers lequel se deplacer   
 
###echo : 
Prend plusieurs arguments et les re-prompts  

###env : 
Prend en argument le nom d'une variable d'environnement et affiche son contenu 
 
###ls : 
Ne prend pas d'argument et liste les fichiers et sous repertoires du répertoire courant  
 
###mv : 
Prend en argument le nom du fichier source et le nom du fichier destinataire  
 
###pwd : 
Ne prend aucun argument et affiche le répertoire courant  
 
###rm : 
Prend en argument le nom du fichier et le supprime 
 
###touch : 
Prend en argument le nom d'un fichier et le créer


###Le mini shell embarque également l'ensemble des commandes système accessibles dans le répertoire /bin

ex : `mkdir`, `rmdir`, `clear`, ...

## Compilation et run du shell
```
arthur@debian:~/Documents/projet-Shell/Shell$ cmake --build /home/arthur/Documents/projet-Shell/Shell/cmake-build-debug --target Shell -- -j 3
Scanning dependencies of target Shell
[  7%] Building C object CMakeFiles/Shell.dir/source/cmd_sys.c.o
[ 14%] Linking C executable Shell
[100%] Built target Shell
arthur@debian:~/Documents/projet-Shell/Shell$ ls
cmake-build-debug  CMakeFiles  CMakeLists.txt  header  LICENSE  README.md  source  test
arthur@debian:~/Documents/projet-Shell/Shell$ cd cmake-build-debug/
arthur@debian:~/Documents/projet-Shell/Shell/cmake-build-debug$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile  Shell  Shell.cbp  test.txt
arthur@debian:~/Documents/projet-Shell/Shell/cmake-build-debug$ ./Shell 
arthur@debian $ ls
Shell.cbp   ..   Shell   cmake_install.cmake   CMakeCache.txt   Makefile   CMakeFiles   test.txt   .   
```