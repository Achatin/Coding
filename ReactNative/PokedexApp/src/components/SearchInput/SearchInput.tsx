import React from 'react';
import { StyleSheet, TextInput, View } from 'react-native';
import Icon from 'react-native-vector-icons/Ionicons';
import colors from '../../styles/colors';

type Props = {
  onSearch: (text: string) => void;
};

const SearchInput = ({ onSearch }: Props) => {
  return (
    <View style={styles.inputWrapper}>
      <Icon name="search" size={20} color={colors.amber} />
      <TextInput
        style={styles.input}
        placeholder="Search"
        placeholderTextColor={colors.amber}
        maxLength={20}
        onChangeText={onSearch}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  inputWrapper: {
    backgroundColor: colors.monza,
    padding: 10,
    flexDirection: 'row',
    alignItems: 'center',
  },
  input: {
    color: colors.amber,
    flex: 1,
    height: 30,
    padding: 4,
  },
});

export default SearchInput;
