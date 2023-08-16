import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Map with Points',
      home: MapWithPoints(),
    );
  }
}

class MapWithPoints extends StatefulWidget {
  @override
  MapWithPointsState createState() => MapWithPointsState();
}

class MapWithPointsState extends State<MapWithPoints> {
  final List<LatLng> points = [
    LatLng(51.505, -0.09),
    LatLng(51.51, -0.1),
    LatLng(51.5, -0.08),
    // Add more points as needed
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Interactive Map'),
      ),
      body: Column(
        children: [
          Expanded(
            child: FlutterMap(
              options: MapOptions(
                center: LatLng(51.505, -0.09),
                zoom: 13.0,
              ),
              children: [
                TileLayer(
                  urlTemplate:
                      'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png',
                  subdomains: ['a', 'b', 'c'],
                ),
                MarkerLayer(
                  markers: points.map((point) {
                    return Marker(
                      width: 25.0,
                      height: 25.0,
                      point: point,
                      builder: (ctx) => Container(
                        decoration: BoxDecoration(
                          color: Colors.blue,
                          shape: BoxShape.circle,
                        ),
                      ),
                    );
                  }).toList(),
                ),
              ],
            ),
          ),
          Row(
            // Under map stuff
          ),
        ],
      ),
    );
  }
}
