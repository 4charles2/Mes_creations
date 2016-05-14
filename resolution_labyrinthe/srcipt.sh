#!/bin/bash
tab=" "
echo "Nombre d'argument : "$#

./labyrinthe 20 20 > $tab
./resolve_laby  $tab
