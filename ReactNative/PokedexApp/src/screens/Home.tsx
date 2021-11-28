import React, { useState } from 'react';
import {
  Button,
  SafeAreaView,
  StyleSheet,
  Text,
  TextInput,
} from 'react-native';

const Home = () => {
  const [text, setText] = useState('Kôlnička');
  const [name, setName] = useState('');

  const handlePress = () => {
    setText(name);
  };

  const handleChangeText = (text: string) => {
    setName(text);
  };

  return (
    <SafeAreaView style={styles.container}>
      <Text style={styles.text}>Ahoj {text}!</Text>
      <TextInput style={styles.input} onChangeText={handleChangeText} />
      <Button title="Change text" onPress={handlePress} />
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  text: {
    fontSize: 32,
    marginBottom: 16,
  },
  input: {
    borderWidth: 1,
    padding: 8,
    width: 100,
    marginBottom: 16,
  },
});

export default Home;
