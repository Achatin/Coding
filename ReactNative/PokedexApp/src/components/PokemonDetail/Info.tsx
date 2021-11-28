import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import Label from '../Label/Label';

type Props = {
  label: string;
  info: string;
};

const Info = ({ label, info }: Props) => {
  return (
    <View style={styles.info}>
      <Label>{label}</Label>
      <Text>{info}</Text>
    </View>
  );
};

const styles = StyleSheet.create({
  info: {
    flexDirection: 'row',
    alignItems: 'center',
  },
});

export default Info;
