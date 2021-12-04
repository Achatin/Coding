import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { transformDashedText } from '../../utils';
import StatIndicator from '../StatIndicator/StatIndicator';
import { Stat as StatType } from '../../types';

type Props = {
  stat: StatType;
};

const Stat = ({ stat }: Props) => {
  return (
    <View style={styles.stat}>
      <Text style={styles.label}>{transformDashedText(stat.stat.name)}</Text>
      <StatIndicator stat={stat.base_stat} />
    </View>
  );
};

const styles = StyleSheet.create({
  stat: {
    flexDirection: 'row',
    width: '100%',
    paddingVertical: 8,
  },
  label: {
    flex: 1,
  },
});

export default Stat;
