echo "\033[01;34mGestion d'erreur\033[00m"
echo "\033[0;35m--> aucun argument : \033[00m" && ./fdf
echo "\033[0;35m--> 2 maps en argument : \033[00m" && ./fdf maps/plat.fdf maps/basictest.fdf
echo "\033[0;35m--> mauvais fd : \033[00m" && ./fdf nofile
echo "\033[0;35m--> ligne plus courte : \033[00m" && ./fdf maps/wrong_map.fdf
echo "\033[0;35m--> map vide : \033[00m" && ./fdf maps/map_vide.fdf
echo "\033[0;35m--> /dev/null : \033[00m" && ./fdf /dev/null
echo "\033[0;35m--> map que des espaces : \033[00m" && ./fdf maps/maps_onlyspaces.fdf
echo "\033[0;35m--> une lettre en hauteur : \033[00m" && ./fdf maps/pars_data.fdf
echo "\033[0;35m--> /dev/random : \033[00m" && ./fdf /dev/random
echo "\033[0;35m--> format couleur : \033[00m" && ./fdf maps/pars_color.fdf

echo "\033[01;34mTests basiques\033[00m"
./fdf maps/plat.fdf
./fdf maps/basictest.fdf
./fdf maps/pnp_flat.fdf
./fdf maps/42.fdf
./fdf maps/pentenegpos.fdf

echo "\033[01;34mTests moyens\033[00m"
./fdf maps/10-2.fdf
./fdf maps/50-4.fdf
./fdf maps/pyra.fdf
./fdf maps/elem.fdf

echo "\033[01;34mTests grande map\033[00m"
./fdf maps/100-6.fdf
./fdf maps/mars.fdf

echo "\033[01;34mTests altitude\033[00m"
./fdf maps/10-70.fdf
./fdf maps/20-60.fdf
./fdf maps/elem2.fdf

echo "\033[01;34mTests couleurs\033[00m"
./fdf maps/pyramide.fdf
./fdf maps/elem-col.fdf

echo "\033[01;34mTests couleurs et altitude\033[00m"
./fdf maps/t1.fdf
./fdf maps/t2.fdf

echo "\033[01;34mTests fractales\033[00m"
./fdf maps/julia.fdf
./fdf maps/elem-fract.fdf
