import React, { useEffect, useState } from 'react';
import { SafeAreaView, StyleSheet } from 'react-native';
import api from '../api';
import PokemonListComponent from '../components/PokemonList/PokemonList';
import { PokemonListItem } from '../types';

const PokemonList = () => {
  const [pokemonList, setPokemonList] = useState<PokemonListItem[]>([]);

  useEffect(() => {
    const fetchPokemonList = async () => {
      const response = await api().get('pokedex/2/');

      const pokemonList = response.data.pokemon_entries;

      setPokemonList(pokemonList);
    };

    fetchPokemonList();
  }, []);

  return (
    <SafeAreaView style={styles.container}>
      <PokemonListComponent pokemonList={pokemonList} />
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});

export default PokemonList;
