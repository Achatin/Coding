import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import Pokeball from '../../assets/icons/Pokeball';
import colors from '../../styles/colors';

const MAX_STAT_LEVEL = 10;
const MAX_STAT_VALUE = 255;

type Props = {
  stat: number;
};

const StatIndicator = ({ stat }: Props) => (
  <View style={styles.container}>
    <Text style={styles.statValue}>{stat}</Text>
    <View style={styles.statIndicator}>
      {[...Array(MAX_STAT_LEVEL).keys()].map((index) => {
        const isFilled =
          index < Math.ceil(stat / (MAX_STAT_VALUE / MAX_STAT_LEVEL));
        const backgroundColor = isFilled ? colors.sanMarino : colors.silver;

        return <Pokeball key={index} size={16} color={backgroundColor} />;
      })}
    </View>
  </View>
);

const styles = StyleSheet.create({
  container: {
    flex: 2,
    flexDirection: 'row',
    justifyContent: 'space-around',
  },
  statValue: {
    flex: 1,
    paddingRight: 8,
    textAlign: 'center',
    fontWeight: 'bold',
  },
  statIndicator: {
    flex: 5,
    flexDirection: 'row',
    justifyContent: 'space-between',
  },
});

export default StatIndicator;
