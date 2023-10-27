import { Component, OnInit } from '@angular/core';
import { Observable, map } from 'rxjs';
import { OmdbapiService, SearchType } from '../services/omdbapi.service';

@Component({
  selector: 'app-movies',
  templateUrl: './movies.page.html',
  styleUrls: ['./movies.page.scss'],
})
export class MoviesPage implements OnInit {
  result!: Observable<any>;
  searchTerms: string = '';
  type: SearchType = SearchType.all;

  constructor(private omdbapi: OmdbapiService) { }

  ngOnInit() {
  }

  search() {
    this.result = this.omdbapi
    .getAll(this.searchTerms, this.type)
    .pipe(map(results => results['Search']));
  }

}
