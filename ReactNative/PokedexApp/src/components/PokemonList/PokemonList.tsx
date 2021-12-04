import React, { useState } from 'react';
import { FlatList, ListRenderItemInfo, StyleSheet, View } from 'react-native';
import SearchInput from '../SearchInput/SearchInput';
import PokemonListItem from './PokemonListItem';
import { PokemonListItem as PokemonListItemType } from '../../types';

type Props = {
  pokemonList: PokemonListItemType[];
};

const PokemonList = ({ pokemonList }: Props) => {
  const [filteredPokemonList, setFilteredPokemonList] = useState<
    PokemonListItemType[]
  >([]);

  const filterPokemon = (text: string) => {
    const filteredPokemonList = pokemonList.filter((pokemon) =>
      pokemon.pokemon_species.name.includes(text.toLowerCase())
    );

    setFilteredPokemonList(filteredPokemonList);
  };

  const renderItem = ({ item }: ListRenderItemInfo<PokemonListItemType>) => {
    return <PokemonListItem item={item} />;
  };

  const data =
    filteredPokemonList.length > 0 ? filteredPokemonList : pokemonList;

  return (
    <View style={styles.container}>
      <SearchInput onSearch={filterPokemon} />
      <FlatList
        style={styles.list}
        data={data}
        renderItem={renderItem}
        keyExtractor={(item) => item.pokemon_species.url}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    width: '100%',
  },
  list: {
    paddingHorizontal: 40,
    width: '100%',
  },
});

export default PokemonList;
