import React from 'react';
import { Image, StyleSheet, View } from 'react-native';
import { Pokemon } from '../../types';
import { getPokemonImageById, transformInfo } from '../../utils';
import Label from '../Label/Label';
import Info from './Info';
import InfoList from './InfoList';
import Stat from './Stat';

type Props = {
  pokemon: Pokemon;
};

const PokemonDetail = ({ pokemon }: Props) => {
  return (
    <View style={styles.container}>
      <View style={styles.mainInfoWithImage}>
        <View style={styles.mainInfoTextWrapper}>
          <View>
            <Info label="Height: " info={transformInfo(pokemon.weight, 'm')} />
            <Info label="Weight: " info={transformInfo(pokemon.weight, 'kg')} />
          </View>
          <InfoList
            label="Abilities:"
            list={pokemon.abilities.map((ability) => ability.ability)}
          />
          <InfoList
            label="Types:"
            list={pokemon.types.map((type) => type.type)}
          />
        </View>
        <Image
          style={styles.image}
          source={{ uri: getPokemonImageById(pokemon.id) }}
        />
      </View>
      <Label>Stats:</Label>
      {pokemon.stats.map((stat) => (
        <Stat key={stat.stat.name} stat={stat} />
      ))}
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 32,
    width: '100%',
  },
  mainInfoWithImage: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    marginBottom: 16,
  },
  mainInfoTextWrapper: {
    justifyContent: 'space-between',
    paddingVertical: 16,
  },
  image: {
    width: 200,
    height: 200,
  },
});

export default PokemonDetail;
