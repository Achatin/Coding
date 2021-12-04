import { useNavigation } from '@react-navigation/native';
import { NativeStackNavigationProp } from '@react-navigation/native-stack';
import React from 'react';
import { Image, StyleSheet, Text, TouchableOpacity } from 'react-native';
import { PokemonStackParamList } from '../../App';
import colors from '../../styles/colors';
import { capitalizeFirstLetter, getPokemonImageById } from '../../utils';
import { PokemonListItem as PokemonListItemType } from '../../types';

type Props = {
  item: PokemonListItemType;
};

const PokemonListItem = ({ item }: Props) => {
  const navigation =
    useNavigation<NativeStackNavigationProp<PokemonStackParamList>>();

  const handlePress = () => {
    navigation.navigate('PokemonDetail', {
      id: item.entry_number,
      name: item.pokemon_species.name,
    });
  };

  return (
    <TouchableOpacity style={styles.container} onPress={handlePress}>
      <Image
        style={styles.image}
        source={{
          uri: getPokemonImageById(item.entry_number),
        }}
      />
      <Text style={styles.label}>
        {capitalizeFirstLetter(item.pokemon_species.name)}
      </Text>
    </TouchableOpacity>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingVertical: 10,
    flexDirection: 'row',
    alignItems: 'center',
    borderColor: colors.silver,
    borderBottomWidth: 1,
  },
  image: {
    marginRight: 32,
    height: 64,
    width: 64,
  },
  label: {
    fontSize: 16,
    color: colors.sanMarino,
  },
});

export default PokemonListItem;
