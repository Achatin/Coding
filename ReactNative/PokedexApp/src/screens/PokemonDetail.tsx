import { NativeStackScreenProps } from '@react-navigation/native-stack';
import React, { useEffect, useState } from 'react';
import { SafeAreaView, StyleSheet } from 'react-native';
import api from '../api';
import { PokemonStackParamList } from '../App';
import PokemonDetailComponent from '../components/PokemonDetail/PokemonDetail';
import { Pokemon } from '../types';

type Props = NativeStackScreenProps<PokemonStackParamList, 'PokemonDetail'>;

const PokemonDetail = ({ route }: Props) => {
  const { params } = route;
  const { id } = params;

  const [pokemon, setPokemon] = useState<Pokemon>();

  useEffect(() => {
    const fetchPokemon = async () => {
      const response = await api().get(`pokemon/${id}`);

      setPokemon(response.data);
    };

    fetchPokemon();
  }, [id]);

  if (!pokemon) {
    return null;
  }

  return (
    <SafeAreaView style={styles.container}>
      <PokemonDetailComponent pokemon={pokemon} />
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

export default PokemonDetail;
